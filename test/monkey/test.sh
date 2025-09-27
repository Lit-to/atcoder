#!/bin/bash
set -e

CONFIG_FILE="$1"
pushd "$(dirname "$0")" > /dev/null || exit 1

TEST_CASE="TEST"
OUTPUT_DIR="OUTPUT"
TLE_BOARDER=2000

if [ ! -f "$CONFIG_FILE" ]; then
    echo "config file not found: $CONFIG_FILE" >&2
    exit 1
fi

# 出力先ディレクトリ作り直し
rm -drf "$TEST_CASE"
# rm -drf "$OUTPUT_DIR"
mkdir -p "$TEST_CASE"
# mkdir -p "$OUTPUT_DIR"

# 設定ファイルから順番に読み込む
INPUT_FILE=$(sed -n '1p' "$CONFIG_FILE")
SCRIPT_A=$(sed -n '2p' "$CONFIG_FILE")
SCRIPT_B=$(sed -n '3p' "$CONFIG_FILE")

# 1行目: テストケース生成
echo "=== Run 1st command: $INPUT_FILE ==="
eval "$INPUT_FILE" 

ng_cases=()

# 2行目: スクリプトA
OUTFILE="$OUTPUT_DIR/result_$(date +%Y%m%d_%H%M%S).log"
echo "=== Test started at $(date) ===" > "$OUTFILE"
total_a=0
total_b=0
count=0
over_a=0
over_b=0
diff_ng=0

for tc in $(ls "$TEST_CASE"/test_*.txt | sort -V); do
    echo "--- Testcase: $tc ---" >> "$OUTFILE"

    OUT1=$(mktemp)
    OUT2=$(mktemp)

    # 実行
    # --- Script A ---
    start=$(date +%s%N)
    eval "$SCRIPT_A" < "$tc" > "$OUT1" 2>>"$OUTFILE"
    end=$(date +%s%N)
    elapsed_a=$(( (end - start) / 1000000 )) # ms単位
    echo "Time (A): ${elapsed_a} ms" >> "$OUTFILE"

    # --- Script B ---
    start=$(date +%s%N)
    eval "$SCRIPT_B" < "$tc" > "$OUT2" 2>>"$OUTFILE"
    end=$(date +%s%N)
    elapsed_b=$(( (end - start) / 1000000 ))
    echo "Time (B): ${elapsed_b} ms" >> "$OUTFILE"

    # 集計
    total_a=$(( total_a + elapsed_a ))
    total_b=$(( total_b + elapsed_b ))
    count=$(( count + 1 ))
    [ $elapsed_a -gt $TLE_BOARDER ] && over_a=$(( over_a + 1 ))
    [ $elapsed_b -gt $TLE_BOARDER ] && over_b=$(( over_b + 1 ))

    # 差分
    if diff -u "$OUT1" "$OUT2" >> "$OUTFILE"; then
        echo "OK: no difference" >> "$OUTFILE"
    else
        echo "NG: difference found" >> "$OUTFILE"
        diff_ng=$(( diff_ng + 1 ))
        ng_cases+=("$tc") 

    fi
    echo >> "$OUTFILE"  # 区切り

    rm -f "$OUT1" "$OUT2"
done

# 平均計算
if [ $count -gt 0 ]; then
    avg_a=$(( total_a / count ))
    avg_b=$(( total_b / count ))
else
    avg_a=0
    avg_b=0
fi
echo "=== Test finished at $(date) ===" >> "$OUTFILE"

# --- NG一覧を文字列化（ファイル用） ---
ng_list=""
for case in "${ng_cases[@]}"; do
    ng_list+="  $case\n"
done

summary="=== Summary ===
Total testcases: $count
NG (difference) : $diff_ng
Avg Time (A)    : ${avg_a} ms
Avg Time (B)    : ${avg_b} ms
TLE:$TLE_BOARDER+ms (A)  : $over_a
TLE:$TLE_BOARDER+ms (B)  : $over_b

$ng_list
"

# --- ファイル冒頭に挿入（色なし） ---
{
    echo -e "$summary"
    cat "$OUTFILE"
} > "${OUTFILE}.tmp" && mv "${OUTFILE}.tmp" "$OUTFILE"

# --- ターミナル出力（色付き） ---
# 色決定
if [ $diff_ng -gt 0 ] || [ $over_a -gt 0 ] || [ $over_b -gt 0 ]; then
    summary_color="\033[31m"  # 赤
else
    summary_color="\033[32m"  # 緑
fi

echo -e "${summary_color}======== Summary ========\033[0m"

# NG部分に赤✖、TLE:2000ms部分も赤✖にする
ng_text="NG (difference) : "
[ $diff_ng -gt 0 ] && ng_text+="\033[31m✖ $diff_ng\033[0m" || ng_text+="0"

over_text_a="TLE:$TLE_BOARDER+ms (A) : "
[ $over_a -gt 0 ] && over_text_a+="\033[31m✖ $over_a\033[0m" || over_text_a+="$over_a"

over_text_b="TLE:$TLE_BOARDER+ms (B) : "
[ $over_b -gt 0 ] && over_text_b+="\033[31m✖ $over_b\033[0m" || over_text_b+="$over_b"

# 出力
echo "Total testcases: $count"
echo -e "$ng_text"
echo "Avg Time (A)    : ${avg_a} ms"
echo "Avg Time (B)    : ${avg_b} ms"
echo -e "$over_text_a"
echo -e "$over_text_b"
echo -e "${summary_color}======== Summary ========\033[0m"

# NG一覧 5件だけ
if [ ${#ng_cases[@]} -gt 0 ]; then
    echo -e "\n\033[31mNG Cases (first 5):\033[0m"
    for case in "${ng_cases[@]:0:5}"; do
        echo "  $case"
    done
fi
echo "Saved $OUTFILE."
./remove.sh
popd > /dev/null

#!/bin/bash
set -e

CONFIG_FILE="$1"
pushd "$(dirname "$0")" > /dev/null || exit 1

TEST_CASE="TEST"
OUTPUT_DIR="OUTPUT"

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

# 2行目: スクリプトA
OUTFILE="$OUTPUT_DIR/result_$(date +%Y%m%d_%H%M%S).log"
echo "=== Test started at $(date) ===" > "$OUTFILE"
total_a=0
total_b=0
count=0
over_a=0
over_b=0
diff_ng=0

for tc in "$TEST_CASE"/*.txt; do
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
    [ $elapsed_a -gt 2000 ] && over_a=$(( over_a + 1 ))
    [ $elapsed_b -gt 2000 ] && over_b=$(( over_b + 1 ))

    # 差分
    if diff -u "$OUT1" "$OUT2" >> "$OUTFILE"; then
        echo "OK: no difference" >> "$OUTFILE"
    else
        echo "NG: difference found" >> "$OUTFILE"
        diff_ng=$(( diff_ng + 1 ))

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

# NG一覧を文字列化
ng_list="NG Cases:\n"
for case in "${ng_cases[@]}"; do
    ng_list+="  $case\n"
done

summary="=== Summary ===
Total testcases: $count
NG (difference) : $diff_ng
Avg Time (A)    : ${avg_a} ms
Avg Time (B)    : ${avg_b} ms
Over2000 (A)    : $over_a
Over2000 (B)    : $over_b

$ng_list
"

# ファイル冒頭に挿入
{
    "$summary"
    "$OUTFILE"
} > "${OUTFILE}.tmp" && mv "${OUTFILE}.tmp" "$OUTFILE"

# ターミナル出力
echo -e "\033[36m======== Summary ========\033[0m"
echo "Total testcases: $count"
echo -e "NG (difference) : \033[31m$diff_ng\033[0m"
echo "Avg Time (A): ${avg_a} ms"
echo "Avg Time (B): ${avg_b} ms"
echo "Over2000 (A): $over_a"
echo "Over2000 (B): $over_b"

if [ ${#ng_cases[@]} -gt 0 ]; then
    echo -e "\n\033[31mNG Cases (first 5):\033[0m"
    for case in "${ng_cases[@]:0:5}"; do
        echo "  $case"
    done
fi
echo "結果は $OUTFILE に保存しました"
popd > /dev/null

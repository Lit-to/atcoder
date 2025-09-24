#!/bin/bash
set -e

CONFIG_FILE="$1"
pushd "$(dirname "$0")" > /dev/null || exit 1

OUTPUT_DIR="TEST"

if [ ! -f "$CONFIG_FILE" ]; then
    echo "config file not found: $CONFIG_FILE" >&2
    exit 1
fi

# 出力先ディレクトリ作成
mkdir -p "$OUTPUT_DIR"

# 設定ファイルから順番に読み込む
INPUT_FILE=$(sed -n '1p' "$CONFIG_FILE")
SCRIPT_A=$(sed -n '2p' "$CONFIG_FILE")
SCRIPT_B=$(sed -n '3p' "$CONFIG_FILE")

# 1行目: テストケース生成
echo "=== Run 1st command: $INPUT_FILE ==="
eval "$INPUT_FILE" 

# 2行目: スクリプトA
echo "=== Run 2nd command: $SCRIPT_A ==="
eval "$SCRIPT_A" < "$OUTPUT_DIR/testcase.txt" > "$OUTPUT_DIR/out1.txt"

# 3行目: スクリプトB
echo "=== Run 3rd command: $SCRIPT_B ==="
eval "$SCRIPT_B" < "$OUTPUT_DIR/testcase.txt" > "$OUTPUT_DIR/out2.txt"

# 差分表示
echo "=== Diff between outputs ==="
diff -u "$OUTPUT_DIR/out1.txt" "$OUTPUT_DIR/out2.txt" || true
popd > /dev/null


# スクリプトのディレクトリに移動
SCRIPT_DIR="$(dirname "$(realpath "$0")")"
pushd "$SCRIPT_DIR" > /dev/null

# 第一引数: プロファイルする Python スクリプト
SCRIPT="$1"

# 第二引数: 入力データ (オプション)
INPUT_FILE="$2"

# 一時コピー用のファイル名
TMP_SCRIPT="${SCRIPT%.py}_profiled"

# コピーを作成
cp "$SCRIPT" "$TMP_SCRIPT"

# @profile を追加
sed -i '/^def /i @profile' "$TMP_SCRIPT"

# プロファイリングを実行（入力ファイルがある場合とない場合で処理を分ける）
if [[ -n "$INPUT_FILE" ]]; then
    kernprof -l -v -o prof_binary "$TMP_SCRIPT" < "$INPUT_FILE" > prof.txt
else
    kernprof -l -v -o prof_binary "$TMP_SCRIPT" > prof.txt
fi

# 一時ファイルを削除
rm "$TMP_SCRIPT"
rm "prof_binary"

popd > /dev/null
echo "profile finished."
# read


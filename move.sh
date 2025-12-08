#!/usr/bin/env bash
set -euo pipefail
# 引数
subject="${1:-}"  # 引数がなければ空文字
# 作業対象ディレクトリ（必要なら絶対パスに変えてください）
DEV_DIR="./dev"

# 出力先のルート
DEST_ROOT="./submission"

# 正規表現（拡張正規表現）
# ^A.C    : A と C の間に任意の1文字
# [0-9]{3}: 3桁の数字
# [A-G]   : A〜G の1文字
# \.[^.]+$: 拡張子（ドットに続く1文字以上、スラッシュは含まない）
RE='^A.C[0-9]{3}[A-G]\.[^.]+$'

if [[ ! -d "$DEV_DIR" ]]; then
    echo "エラー: $DEV_DIR が見つかりません。" >&2
    exit 1
fi

# マッチするファイルを null 区切りで収集（サブディレクトリは検索しない）
mapfile -d '' -t matches < <(find "$DEV_DIR" -maxdepth 1 -type f -print0 | while IFS= read -r -d '' f; do
    base=$(basename "$f")
    if [[ $base =~ $RE ]]; then
        printf '%s\0' "$f"
    fi
done)

if (( ${#matches[@]} == 0 )); then
    echo "マッチするファイルは見つかりませんでした。"
    exit 0
fi

echo "以下のファイルがマッチしました:"
for f in "${matches[@]}"; do
    echo "    - $f"
done

# 確認
read -r -p "移動しますか? [y/n] " answer
if [[ "$answer" != "y" ]]; then
    echo "キャンセルしました。"
    exit 0
fi

# 移動処理
for f in "${matches[@]}"; do
    base=$(basename "$f")
    # A?C を取り出す（先頭の3文字：A + 任意1文字 + C）
    aqc="${base:0:3}"
    # A?C + 3桁 を取り出してディレクトリ名に（先頭6文字：A?C + 3桁）
    # 例: A?C123X.ext -> A?C123
    dirpart="${base:0:6}"

    dest_dir="$DEST_ROOT/$aqc/$dirpart"
    mkdir -p "$dest_dir"
    mv -- "$f" "$dest_dir/"
    echo "Moved: '$base' -> '$dest_dir/'"
done


# --- ここから commit メッセージ作成 ---
commit_msg="${subject}"$'\n'
commit_msg+="↓ACした"$'\n'
for f in "${matches[@]}"; do
    commit_msg+="-   $(basename "$f")"$'\n'
done

# git add 対象（必要に応じて調整）
git add *

# コミット
git commit -m "$commit_msg"


echo "完了しました。"

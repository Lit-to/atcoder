#!/usr/bin/env bash

OLD_DIR="$PWD"

cd ~/atcoder/ || { echo "ディレクトリ ~/atcoder/ に移動できません"; exit 1; }

if [ $# -ge 1 ]; then
    fileName="$1"
else
    read -p "作成ファイル名 (例: ABC334A): " fileName
fi

# 拡張子があれば ext と basename を分離、なければ py をデフォルト
if [[ "$fileName" == *.* ]]; then
    ext="${fileName##*.}"
    basename="${fileName%.*}"
else
    ext="cpp"
    basename="$fileName"
    fileName="${basename}.${ext}"
fi

template="material/template.${ext}"
if [ ! -f "$template" ]; then
    echo "対応するテンプレートファイルが見つかりません: $template" >&2
    exit 1
fi

mkdir -p dev
cp "$template" "dev/$fileName"

# 1行目の先頭 2 文字を残し、その直後に basename を挿入
sed -i "1s/^\([^[:space:]]\+\).*/\1 ${basename}/" "dev/$fileName"


printf '作成: dev/%s\nテンプレート %s → コピー。1行目に "%s" を挿入\n' \
        "$fileName" "$template" "$basename"

cd "$OLD_DIR"

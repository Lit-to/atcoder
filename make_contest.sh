#!/bin/bash

# コンテスト名をユーザーに聞く
read -p "コンテスト名を入力してください: " CONTEST

# 大文字に変換
CONTEST_UPPER=$(echo "$CONTEST" | tr '[:lower:]' '[:upper:]')

# ディレクトリが存在するか確認
if [ ! -d "./TEMPLATE" ]; then
  echo "エラー: ./TEMPLATE ディレクトリが存在しません。"
  exit 1
fi

# ./dev ディレクトリがなければ作る
mkdir -p ./dev

# TEMPLATE 配下のファイルを処理
for FILE in ./TEMPLATE/*; do
  BASENAME=$(basename "$FILE")                              # 例: main.py
  BASENAME_NO_EXT="${BASENAME%.*}"                          # 例: main
  NEWNAME="${CONTEST_UPPER}${BASENAME}"                     # 例: ABC123main.py
  DEST="./dev/${NEWNAME}"

  COMMENT_LINE="# ${CONTEST_UPPER}${BASENAME_NO_EXT}"       # 1行目コメント

  # 先頭にコメントを追加して保存
  echo "$COMMENT_LINE" > "$DEST"
  cat "$FILE" >> "$DEST"
done

# 完了メッセージ
echo "✅ ${CONTEST_UPPER} のテンプレートコピーとリネーム（大文字＆コメント付き）が完了しました。"

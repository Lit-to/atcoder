#!/bin/bash

# コピー元のファイルパス
# cd lang/java
SOURCE_FILE="$1"

# コピー先のディレクトリパス
FOLDER_NAME=$(head -n 1 "$SOURCE_FILE" | awk '{print $2}' | tr '[:lower:]' '[:upper:]')
if ! [[ "$FOLDER_NAME" =~ ^[A-Za-z]{3}[0-9]{3}[A-H]$ ]]; then
    echo "Error: The folder name must be in the format 'abc' followed by three digits."
    exit 1
fi
DEST_DIR="dev/"

# コピー先のファイル名
CLASS_NAME=$(head -n 1 "$SOURCE_FILE" | awk '{print $3}')
# if ! [[ "$CLASS_NAME" =~ ^[a-zA-Z]$ ]]; then
#     echo "Error: The class name must be a single letter."
#     exit 1
# else
#     CLASS_NAME=$(echo "$CLASS_NAME" | tr '[:upper:]' '[:lower:]')
# fi

DEST_FILE="${CLASS_NAME}.java"

# コピー先ディレクトリが存在しない場合は作成
mkdir -p "$DEST_DIR"

# ファイルをコピーしてリネーム
cp "$SOURCE_FILE" "$DEST_DIR/$FOLDER_NAME$DEST_FILE"
echo "ファイルをコピーしてリネームしました: $DEST_DIR/$FOLDER_NAME$DEST_FILE"
# コンパイル
javac -encoding UTF-8 "./$SOURCE_FILE" -d "./lang/output" 


#!/bin/bash

# コピー元のファイルパス
SOURCE_FILE="$1"

# コピー先のディレクトリパス
FOLDER_NAME=$(head -n 1 "$SOURCE_FILE" | awk '{print $2}' | tr '[:upper:]' '[:lower:]')
if ! [[ "$FOLDER_NAME" =~ ^abc[0-9]{3}$ ]]; then
    echo "Error: The folder name must be in the format 'abc' followed by three digits."
    exit 1
fi
DEST_DIR="contest/java/$FOLDER_NAME"

# コピー先のファイル名
CLASS_NAME=$(head -n 1 "$SOURCE_FILE" | awk '{print $3}')
if ! [[ "$CLASS_NAME" =~ ^[a-zA-Z]$ ]]; then
    echo "Error: The class name must be a single letter."
    exit 1
else
    CLASS_NAME=$(echo "$CLASS_NAME" | tr '[:upper:]' '[:lower:]')
fi
DEST_FILE="${CLASS_NAME}.java"

# コピー先ディレクトリが存在しない場合は作成
mkdir -p "$DEST_DIR"

# ファイルをコピーしてリネーム
cp "$SOURCE_FILE" "$DEST_DIR/$DEST_FILE"

echo "ファイルをコピーしてリネームしました: $DEST_DIR/$DEST_FILE"

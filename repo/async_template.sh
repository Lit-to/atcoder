#!/bin/bash

# 元の作業ディレクトリを保存
ORIGINAL_DIR=$(pwd)

# 作業ディレクトリに移動
TARGET_DIR="repo/../"
cd "$TARGET_DIR" || { echo "作業ディレクトリに移動できませんでした: $TARGET_DIR"; read; exit 1; }

# コピー元ファイルを指定
SOURCE_FILE="material/template.py"

# コピー先パスを指定（スペース区切りで複数指定）
DEST_DIRS="contest/template/a.py contest/template/b.py contest/template/c.py contest/template/d.py contest/template/e.py contest/template/f.py contest/template/g.py"

# ファイルをコピー
for DEST_DIR in $DEST_DIRS; do
    echo "コピー中: $SOURCE_FILE -> $DEST_DIR"
    cp "$SOURCE_FILE" "$DEST_DIR" || echo "コピーに失敗しました: $DEST_DIR"
done

# 元の作業ディレクトリに戻る
cd "$ORIGINAL_DIR" || { echo "元のディレクトリに戻れませんでした: $ORIGINAL_DIR"; exit 1; }
echo "作業が完了しました。元のディレクトリに戻りました: $ORIGINAL_DIR"


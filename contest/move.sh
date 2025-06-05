#!/bin/bash

# contest ディレクトリへ移動
cd contest || exit 1

# ABC* ディレクトリをループ
for dir in ABC*; do
  if [ -d "$dir" ]; then
    for file in "$dir"/*.py; do
      # ファイルが存在するかチェック（ワイルドカード未展開対策）
      [ -e "$file" ] || continue
      # 元のファイル名と新しいファイル名を組み立て
      base_file=$(basename "$file")        # 例: a.py
      new_file="${dir}${base_file}"       # 例: ABC123_a.py
      # 移動
      mv "$file" "../contest/$new_file"
    done
  fi
done

#!/bin/bash

declare -A MOVE_MAP

# ./dev 内のファイルを確認
for FILE in ./dev/*; do
  BASENAME=$(basename "$FILE")

  if [[ "$BASENAME" =~ ^ABC([0-9]{3}) ]]; then
    NUM=${BASH_REMATCH[1]}
    LOW=$(( (10#$NUM / 100) * 100 ))
    HIGH=$((LOW + 99))
    DIRNAME="ABC${LOW}-${HIGH}"
    TARGET_DIR="./submission/python/${DIRNAME}"

  elif [[ "$BASENAME" =~ ^ARC([0-9]{3}) ]]; then
    TARGET_DIR="./submission/python/ARC"

  elif [[ "$BASENAME" =~ ^AGC([0-9]{3}) ]]; then
    TARGET_DIR="./submission/python/AGC"

  else
    echo "⚠️ 無視: $BASENAME は対応するコンテスト名で始まっていません"
    continue
  fi

  MOVE_MAP["$FILE"]="$TARGET_DIR"
done

# 対象がなければ終了
if [ ${#MOVE_MAP[@]} -eq 0 ]; then
  echo "📭 移動するファイルはありません！"
  exit 0
fi

# 確認フェーズ
echo "以下のファイルを移動しようとしています："
echo "----------------------------------------"
for SRC in "${!MOVE_MAP[@]}"; do
  DST="${MOVE_MAP[$SRC]}"
  echo "$(basename "$SRC") → $DST/"
done
echo "----------------------------------------"

# ユーザー確認
read -p "これらのファイルを移動しますか？ (y/n): " CONFIRM
if [[ "$CONFIRM" != "y" && "$CONFIRM" != "Y" ]]; then
  echo "❌ 中止しました。ファイルは移動されていません。"
  exit 0
fi

# 実行フェーズ
for SRC in "${!MOVE_MAP[@]}"; do
  DST="${MOVE_MAP[$SRC]}"
  mkdir -p "$DST"
  mv "$SRC" "$DST/"
  echo "✅ $(basename "$SRC") → $DST に移動しました"
done

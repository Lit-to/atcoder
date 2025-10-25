#!/bin/bash
declare -A MOVE_MAP
declare -a DELETE_LIST

# テンプレートファイルの存在確認
TEMPLATE_PATH="lang/python/material/template.py"
if [ ! -f "$TEMPLATE_PATH" ]; then
  echo "❌ テンプレートファイルが見つかりません: $TEMPLATE_PATH"
  exit 1
fi

# ./dev 内のファイルを確認
for FILE in ./dev/*; do
  [ -f "$FILE" ] || continue
  BASENAME=$(basename "$FILE")

  echo diff -q "$FILE" "$TEMPLATE_PATH" >/dev/null

  # --- template と同一チェック（テキスト比較） ---
  if diff -q "$FILE" "$TEMPLATE_PATH" >/dev/null; then
    DELETE_LIST+=("$FILE")
    continue
  fi
  # -------------------------------

  # --- コンテスト種別を判定 ---
  if [[ "$BASENAME" =~ ^ABC([0-9]{3}) ]]; then
    TARGET_DIR="./submission/python/ABC"

  elif [[ "$BASENAME" =~ ^ARC([0-9]{3}) ]]; then
    TARGET_DIR="./submission/python/ARC"

  elif [[ "$BASENAME" =~ ^AGC([0-9]{3}) ]]; then
    TARGET_DIR="./submission/python/AGC"

  elif [[ "$BASENAME" =~ ^CCD([0-9]{3}) ]]; then
    TARGET_DIR="./submission/python/CCD"

  else
    echo "⚠️ 無視: $BASENAME は対応するコンテスト名で始まっていません"
    continue
  fi

  MOVE_MAP["$FILE"]="$TARGET_DIR"
done

# --- 移動対象の確認 ---
if [ ${#MOVE_MAP[@]} -gt 0 ]; then
  echo "移動対象 >"
  for SRC in "${!MOVE_MAP[@]}"; do
    DST="${MOVE_MAP[$SRC]}"
    echo "・$(basename "$SRC") → $DST/"
  done
  echo
  read -p "上記のファイルを移動しますか？ (y/n): " CONFIRM
  if [[ "$CONFIRM" == "y" || "$CONFIRM" == "Y" ]]; then
    for SRC in "${!MOVE_MAP[@]}"; do
      DST="${MOVE_MAP[$SRC]}"
      mkdir -p "$DST"
      mv "$SRC" "$DST/"
      echo "✅ $(basename "$SRC") → $DST に移動しました"
    done
  else
    echo "🚫 移動はキャンセルされました"
  fi
else
  echo "📭 移動対象はありません"
fi

# --- 削除対象の確認 ---
if [ ${#DELETE_LIST[@]} -gt 0 ]; then
  echo
  echo "削除対象 >"
  for FILE in "${DELETE_LIST[@]}"; do
    echo "・$(basename "$FILE")（template.py と同一内容）"
  done
  echo
  read -p "上記のファイルを削除しますか？ (y/n): " CONFIRM_DEL
  if [[ "$CONFIRM_DEL" == "y" || "$CONFIRM_DEL" == "Y" ]]; then
    for FILE in "${DELETE_LIST[@]}"; do
      rm "$FILE"
      echo "🗑️ $(basename "$FILE") を削除しました"
    done
  else
    echo "🚫 削除はキャンセルされました"
  fi
else
  echo "📭 削除対象はありません"
fi

echo "🎉 全ファイルの処理が完了しました！"

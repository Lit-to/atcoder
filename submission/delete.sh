#!/bin/bash

OLD_DIR="$PWD"
cd ~/atcoder/submission || exit 1

# グループ生成（hash -> ファイル一覧）

declare -A group
declare -A count

while IFS= read -r f; do
hash=$(tail -n +2 "$f" | sha256sum | awk '{print $1}')
group["$hash"]+="$f"$'\n'
((count["$hash"]++))
done < <(find . -type f)

# 各グループ処理

for h in "${!group[@]}"; do
if (( count["$h"] <= 1 )); then
continue
fi

echo "========================="
echo "Group: ${count[$h]} files"

# 配列化

mapfile -t files <<< "${group[$h]}"

# 最初のファイル開く

first="${files[0]}"
echo "Opening: $first"
code "$first"

# 一覧表示

echo "Files:"
for f in "${files[@]}"; do
[[ -n "$f" ]] && echo "  $f"
done

# 確認

read -p "Delete ALL files in this group? (y/n): " ans

if [[ "$ans" == "y" ]]; then
for f in "${files[@]}"; do
[[ -n "$f" ]] && rm "$f"
done
echo "Deleted."
else
echo "Skipped."
fi
done

cd "$OLD_DIR"

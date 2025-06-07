#!/bin/bash

cd contest || exit 1

# reportディレクトリ作成
mkdir -p report

for dir in ABC* ARC* AGC*; do
  if [ -d "$dir" ]; then
    prefix=${dir:0:3}

    if [[ $prefix == "ABC" ]]; then
      num=${dir:3}

      if ! [[ $num =~ ^[0-9]{3}$ ]]; then
        continue
      fi

      num=$((10#$num))
      range_start=$(( (num / 100) * 100 ))
      range_end=$(( range_start + 99 ))
      target_dir="ABC${range_start}-${range_end}"
    else
      target_dir="$prefix"
    fi

    mkdir -p "$target_dir"

    for file in "$dir"/*.py; do
      [ -e "$file" ] || continue

      base_file=$(basename "$file")

      dir_lower=$(echo "$dir" | tr '[:upper:]' '[:lower:]')
      base_lower=$(echo "$base_file" | tr '[:upper:]' '[:lower:]')

      if [[ "$base_lower" == "$dir_lower"* ]]; then
        # フォルダ名で始まってたらリネームしない
        new_file="$target_dir/$base_file"
      else
        # アンダーバー無しで結合
        new_file="$target_dir/${dir}${base_file}"
      fi

      mv "$file" "$new_file"
    done

    # report.mdをreport/に移動（フォルダ名付きでリネーム）
    report_file="$dir/report.md"
    if [ -f "$report_file" ]; then
      mv "$report_file" "report/${dir}report.md"
    fi

    rmdir "$dir" 2>/dev/null
  fi
done

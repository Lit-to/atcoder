#!/bin/bash

cd submission || exit 1

if [ -d others ]; then
  for dir in others/ABC* others/ARC* others/AGC*; do
    if [ -d "$dir" ]; then
      base_dir=$(basename "$dir")
      prefix=${base_dir:0:3}

      if [[ $prefix == "ABC" ]]; then
        num=${base_dir:3}
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

      for file in "$dir"/*; do
        [ -e "$file" ] || continue
        [ -f "$file" ] || continue

        base_file=$(basename "$file")
        dir_lower=$(echo "$base_dir" | tr '[:upper:]' '[:lower:]')
        base_lower=$(echo "$base_file" | tr '[:upper:]' '[:lower:]')

        if [[ "$base_lower" == "$dir_lower"* ]]; then
          new_file="$target_dir/$base_file"
        else
          new_file="$target_dir/${base_dir}${base_file}"
        fi

        mv "$file" "$new_file"
      done

      rmdir "$dir" 2>/dev/null
    fi
  done
fi

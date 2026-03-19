#!/usr/bin/env bash
#================================
# ここに実行コマンドを書く場所
execCommand="../dev/a"

#================================

set -euo pipefail
pushd "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)" > /dev/null
mkdir output
output="./output/$(date +%Y%m%d%H%M%S%3N)"
mkdir $output
RESULT=$output/RESULT
touch $RESULT
echo $execCommand > $RESULT
for file in ./input/*; do
    [ -e "$file" ] || continue
    name=$(basename "$file")
    start=$(date +%s%N)
    $execCommand < $file > $output/$name
    end=$(date +%s%N)
    path=$(realpath "$output/$name")
    echo $(( (end - start) / 1000000 ))"ms => $path" >> $RESULT
done
cat $RESULT
popd > /dev/null

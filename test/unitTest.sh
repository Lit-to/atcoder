#!/usr/bin/env bash
#================================
# ここに実行コマンドを書く場所
execCommand="../dev/a" #Cpp
# execCommand="pypy3 script.py" #Python

#================================

set -euo pipefail
pushd "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)" > /dev/null
output="./output"
mkdir -p $output
RESULT="$output/$(date +%Y%m%d%H%M%S%3N)_TestSummary"
touch $RESULT
echo "Execute Result => $execCommand" > $RESULT
for file in ./input/*.txt; do
    [ -e "$file" ] || continue
    name=$(basename "$file")
    echo "file : $file" >> $RESULT
    echo -e "================\n" >> $RESULT
    start=$(date +%s%N)
    $execCommand < $file >> $RESULT
    end=$(date +%s%N)
    path=$(realpath "$output/$name")
    time=$(( (end - start) / 1000000 ))
    echo -e "\n================" >> $RESULT
    if [ "$time" -gt 2000 ]; then
        echo "[TLE] time: $time ms" >> $RESULT
    else
        echo "[---] time: $time ms" >> $RESULT
    fi
done
resultPath=$(realpath "$RESULT")
echo "Test Summary => " $resultPath
popd > /dev/null

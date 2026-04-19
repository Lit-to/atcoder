#!/usr/bin/env bash
pushd "$(dirname "$0")" > /dev/null
pushd .. > /dev/null

#================================
# ここに実行コマンドを書く場所
execCommand="../dev/a" #Cpp
# execCommand="pypy3 ../dev/ABC452E.py" #Python

#================================
# 引数から受け取り

args=()
isNoTimeLimit=false

for arg in "$@"; do
    if [ "$arg" = "-notl" ]; then
        isNoTimeLimit=true
    else
        args+=("$arg")
    fi
done

if [ "${#args[@]}" -eq 0 ]; then
    execCommand="$execCommand"
else
    execCommand="${args[@]}"
fi

# シェル事故時の救済おまじない
set -euo pipefail

# 出力フォルダ・ファイル作成
output="./output"
mkdir -p $output
RESULT="$output/$(date +%Y%m%d%H%M%S%3N)_TestSummary"
touch $RESULT
echo "Execute Result => $execCommand" > $RESULT

# 入力テキストファイルを上から順に流す
for file in ./input/*.txt; do
    [ -e "$file" ] || continue
    name=$(basename "$file")
    echo "file : $file" >> $RESULT
    echo -e "================\n" >> $RESULT
    
    # 時間計測・実行
    start=$(date +%s%N)
    $execCommand < $file >> $RESULT
    end=$(date +%s%N)
    
    # 計測結果の実行時間出力    
    path=$(realpath "$output/$name")
    time=$(( (end - start) / 1000000 ))
    echo -e "\n================" >> $RESULT
    if [ "$isNoTimeLimit" = true ]; then
        continue
    fi
    if [ "$time" -gt 2000 ]; then
        echo "[TLE] time: $time ms" >> $RESULT
    else
        echo "[---] time: $time ms" >> $RESULT
    fi
done
# パス出力
resultPath=$(realpath "$RESULT")
echo $resultPath
echo "<====== Test Summary"
popd > /dev/null
popd > /dev/null

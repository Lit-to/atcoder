#!/usr/bin/env bash
pushd "$(dirname "$0")" > /dev/null

#================================
# ここに実行コマンドを書く場所
correctProgram="../dev/a" #Cpp

#================================
# 実験対象はそのまま実行
targetResult=$(./unitTest.sh -notl $correctProgram | head -n 1)

# サンプルの出力結果を流す
output="./output"
mkdir -p $output
sampleResult="$output/$(date +%Y%m%d%H%M%S%3N)_TestSummary"
touch $sampleResult
echo "Execute Result => cat (sample_output)" > $sampleResult
for file in ./sample_output/*.txt; do
    [ -e "$file" ] || continue
    name=$(basename "$file")
    echo "file : $file" >> $sampleResult
    echo -e "================\n" >> $sampleResult
    # 実行
    cat $file >> $sampleResult
    # 中身吐き出し結果    
    path=$(realpath "$output/$name")
    echo -e "\n================" >> $sampleResult
done

# 比較結果の出力
code --diff $correctResult $sampleResult
popd

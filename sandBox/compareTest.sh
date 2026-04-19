#!/usr/bin/env bash
pushd "$(dirname "$0")" > /dev/null
#================================
# ここに実行コマンドを書く場所
correctProgram="../dev/b" #Cpp
targetProgram="../dev/a" #Cpp


#================================
# それぞれ実行
correctResult=$(./unitTest.sh -notl $correctProgram | head -n 1)
targetResult=$(./unitTest.sh -notl $targetProgram | head -n 1)

# 比較結果の出力
diff -u $targetResult $sampleResult > ./output/diff.txt
code --diff $targetResult $sampleResult
popd


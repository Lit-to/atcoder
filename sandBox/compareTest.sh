#!/usr/bin/env bash
pushd "$(dirname "$0")" > /dev/null
#================================
# ここに実行コマンドを書く場所
correctProgram="../dev/a" #Cpp
targetProgram="python ../dev/TESOK002B.py" #Cpp
# execCommand="python3 ../dev/ABC452E.py" #Python

#================================
# それぞれ実行
correctResult=$(./unitTest.sh $correctProgram | head -n 1)
targetResult=$(./unitTest.sh $targetProgram | head -n 1)

# 比較結果の出力
code --diff $correctResult $targetResult
popd


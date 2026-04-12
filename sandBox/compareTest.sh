#!/usr/bin/env bash
pushd "$(dirname "$0")" > /dev/null
#================================
# ここに実行コマンドを書く場所
correctProgram="../dev/a" #Cpp
targetProgram="pypy3 ../dev/a.py" #Cpp
# execCommand="python3 ../dev/ABC452E.py" #Python

#================================
correctResult=$(./unitTest.sh $correctProgram | head -n 1)
targetResult=$(./unitTest.sh $targetProgram | head -n 1)
code --diff $correctResult $targetResult
popd


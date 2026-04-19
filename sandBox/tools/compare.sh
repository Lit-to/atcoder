#!/usr/bin/env bash
pushd "$(dirname "$0")" > /dev/null
pushd .. > /dev/null
#================================
# ここに実行コマンドを書く場所
correctProgram="../dev/b" #Cpp
targetProgram="../dev/a" #Cpp


#================================
# それぞれ実行
correctResult=$(./tools/unit.sh -notl $correctProgram | head -n 1)
targetResult=$(./tools/unit.sh -notl $targetProgram | head -n 1)

# 比較結果の出力
diff -u --color=always $targetResult $correctResult | delta > ./output/diff.txt 
code --diff $targetResult $correctResult
popd > /dev/null
popd > /dev/null



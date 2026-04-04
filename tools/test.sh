#!/bin/bash

# 移動（元の場所はスタックに保存される）
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
pushd "$SCRIPT_DIR" > /dev/null
pushd "modules/test"
for file in *.cpp; do
    echo "=== $file ==="
    /usr/bin/g++ -std=c++23 -I ~/acl/ -Ofast "$file" -o a || continue
    ./a
done

for file in *.py; do
    echo "=== $file ==="    
    pypy3 "$file" || continue
done
popd > /dev/null

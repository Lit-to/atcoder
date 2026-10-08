#!/bin/sh

branch="$(git symbolic-ref --short HEAD 2>/dev/null)"

if [ "$branch" = "AHC072" ]; then
    echo "Error: main branchからのpushは禁止されています。"
    exit 1
fi

exit 0
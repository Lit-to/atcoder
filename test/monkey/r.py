#!/usr/bin/env python3
import sys
import random

# ----------------------------
# トークンごとの値生成マップ
# ----------------------------
TOKENS = {
    "N": lambda: str(random.randint(1, 10)),
    "M": lambda: str(random.randint(1, 10)),
    "U": lambda: str(random.randint(1, 100)),
    "V": lambda: str(random.randint(1, 100)),
    "A": lambda: str(random.randint(1, 1000)),
    "1":1
}


SPACE = " "
UNDER_BAR = "_"
ONE = "1"
ARRAY_PREFIX = "..."
FILE_COUNT = 1
FILE_PREFIX = "/test_"
# ----------------------------
# 入力ファイル受け取り
# ----------------------------
if len(sys.argv) < 3:
    print("Usage: python3 gen_cases.py <input_file> <output_directory>", file=sys.stderr)
    sys.exit(1)

def split(s,sep=" "):
    if SPACE in s:
        return s.split(sep)
    else:
        return list(s)

def splitTokens(s):
    tokens = split(s)
    result = []
    for i in range(len(tokens)):
        result.append(splitTokens(tokens[i]))
    return result

def getCount(token):
    """
    token: 'A', 'A_1', 'A_10', 'A_3_1', 'A_N_1', 'A_10_N' など
    values: 以前のトークン値を参照する辞書（必要に応じて）
    
    return: (ベース名, count) すべて文字列
    """
    parts = split(token,"_")
    if len(parts) == 1:
        return token, "1"
    else:
        # 最後のパートを取り出す
        last = parts[-1]
        base = "_".join(parts[:-1])
        # 数字ならそのまま、数字でなければ文字列として返す
        return base, last



def printf(*args,path,mode="a",sep=" "):
    with open(path, mode,encoding="utf-8") as f:
        if args[0] != None:
            print(*args,sep=sep,file=f)

def dump(outputs, path):
    for output in outputs:
        printf(*output, path=path)


input_file = sys.argv[1]
lines = []

directory = sys.argv[2]

try:
    with open(input_file, 'r') as f:
        lines = [line.strip() for line in f.readlines() if line.strip()]
except FileNotFoundError:
    print(f"Input file not found: {input_file}", file=sys.stderr)
    sys.exit(1)

n = len(lines)

outputs = []
for file in range(FILE_COUNT):
    printf(None,path=directory+FILE_PREFIX+str(file),mode="w")
    for i in range(n):
        line = split(lines[i])
        if line[0] == ARRAY_PREFIX:
            token, countKey = getCount(line[i])
            for j in range(TOKENS[countKey]):
                outputs.append(TOKENS[token]())
        else:
            out_line = []
            for j in line:
                out_line.append(TOKENS[j]())
            outputs.append(out_line)
    dump(outputs, directory+FILE_PREFIX+str(file))





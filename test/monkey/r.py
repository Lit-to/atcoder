#!/usr/bin/env python3
import sys
import tokens
TOKENS = tokens.TOKENS

SPACE = " "
UNDER_BAR = "_"
ARRAY_PREFIX = "..."
FILE_COUNT = 1
FILE_PREFIX = "/test_"
# ----------------------------
# 入力ファイル受け取り
# ----------------------------
# if len(sys.argv) < 3:
#     print("Usage: python3 gen_cases.py <input_file> <output_directory>", file=sys.stderr)
#     sys.exit(1)

def split(s,sep=" "):
    if sep in s:
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
        return token, 1
    else:
        # 最後のパートを取り出す
        last:str = parts[-1]
        base = "_".join(parts[:-1])
        if last.isdigit()==False:
            count = values[last]
        else:
            count = int(last)
        return base, count

def getValue(token):
    if token not in values:
        values[token]=TOKENS[token]()
    return values[token]

def printf(*args,path,mode="a",sep=" "):
    with open(path, mode,encoding="utf-8") as f:
        if args[0] != None:
            print(*args,sep=sep,file=f)

def dump(outputs, path):
    for output in outputs:
        if type(output) == list:
            printf(*output, path=path)
        else:
            printf(output,path=path)

input_file = sys.argv[1]
directory = sys.argv[2]
FILE_COUNT = int(sys.argv[3])
# input_file = "test/monkey/input.txt"
# directory = "test/monkey/TEST"
# FILE_COUNT=1
lines = []
try:
    with open(input_file, 'r') as f:
        lines = [line.strip() for line in f.readlines() if line.strip()]
except FileNotFoundError:
    print(f"Input file not found: {input_file}", file=sys.stderr)
    sys.exit(1)

n = len(lines)

for file in range(FILE_COUNT):
    outputs = []
    values = {}
    printf(None,path=directory+FILE_PREFIX+str(file)+".txt",mode="w")
    for i in range(n):
        line = split(lines[i])
        if line[0] == ARRAY_PREFIX:
            token, countKey = getCount(line[i])
            for j in range(int(countKey)):
                outputs.append(TOKENS[token]())
        else:
            out_line = []
            for j in line:
                out_line.append(getValue(j))
            outputs.append(out_line)
    dump(outputs, directory+FILE_PREFIX+str(file)+".txt")





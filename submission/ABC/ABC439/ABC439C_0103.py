# ABC439C
# template

"""
/**
 *方針メモ欄
 *
 * # お気持ち
 * そういう整数を探すより作りに行くほうが楽そう..？
 * 高々3163*3163 が10**7+1を超える程度なので、3163個しか当該整数はない
 * →全列挙全探索でxとyの計算し、nが何回登場したか数える
 * その後N以下のものを全部前から順に出力する
 *
 * # 入力
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 *
 * # 具体的なロジック
 *
 *
 *
 *
 *
 * # 出力
 *
 *
 */
"""

def main():
    # 関数定義スペース

    ...    

    # 入力スペース
    """
    入力受け取り例
    
    # N = split(input(),func=int)[0]
    # H, W = split(input(),func=int)
    # A = split(input(),func=int)
    # S = split(input())[0]
    """
    # num = 1
    # i = 1
    # while num<10**7+1:
    #     i+=1
    #     num = i**2
    # print(i)
    N = int(input())
    d = dict(lambda:0)
    note = dict(lambda:0)
    for i in range(1,3200):
        if i not in note:
            note[i] = i*i
        for j in range(i+1,3200):
            if j not in note:
                note[j] = j*j
            n = note[i]+note[j]
            d[n]+=1
            if N<n:
                break
    result = []
    keys=list(d.keys())
    keys.sort()
    for i in keys:
        if N<i:
            break
        if d[i]==1:
            result.append(i)
    print(len(result))
    print(*result)


    ...

    # 処理スペース






    ...

# テンプレートコピペエリア


# テストケース中枢処理
def case():
    TESTCASE = 1
    # TESTCASE = int(input()) # テストケース数の指定
    for _ in range(TESTCASE):
        try:
            main()
        except solvedException:
            continue
        # raise unSolvedExeption


# インポート
import sys, itertools, math, heapq
from collections import defaultdict, deque
from sortedcontainers import SortedSet, SortedList, SortedDict  # CPython?

# 定数・環境設定
sys.setrecursionlimit(10**8)
sys.set_int_max_str_digits(0)
dict = defaultdict
UPPER_ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
LOWER_ALPHABET="abcdefghijklmnopqrstuvwxyz"
MOD = 998244353
MAX = 10**18
LRUD = [(0, 1), (0, -1), (1, 0), (-1, 0)]
LURULDRD = [(-1, -1), (-1, 1), (1, -1), (1, 1)]

# 各種関数定義
## 便利関数
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end); fin()
def prin(stop=False,sep=" ",end="\n",file=sys.stdout):return (lambda*values:printe(*values,sep=sep,end=end)) if stop else (lambda*values:print(*values,sep=sep,end=end,file=file))
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def printYN(f:bool): yes() if f else no()
def fin(f=True): raise solvedException if f else None
def listbin(num): return split(bin(num)[2:],"",int)

## 分割関数
def split(value:str,sep:str=" ",func:callable=str) -> list:
    """
    分割関数
    文字列をスペース区切りで分割する。
    """
    result = []
    section = 0
    for i in range(len(value)):
        if value[i] == sep:
            result.append(func(value[section:i]))
            section = i
    if i == 0:
        result.append(func(value[section:]))
    elif section != i:
        result.append(func(value[section+1:]))
    return result


## 入力受け取り用
def input():return(sys.stdin.readline()).rstrip() #入力定数倍

# 例外クラス
class solvedException(Exception): pass # 処理打ち切り例外
class unSolvedExeption(Exception): # 回答未出力例外
    def __init__(description = "解答が出力されていません。"): super().__init__(description)

# 実行
if __name__ == "__main__":
    case()

# ABC424c
# 2025-09-20 20:38:35

def main():
    # 関数定義スペース

    def func():
        ...

    ...    
    # 入力スペース

    N = splitN(input())
    H, W = splitA(input())
    A = splitA(input())
    S = splitS(input())
    S = splitB(input())

    ...

    # 処理スペース






    ...



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

# 各種関数定義(超圧縮)
## 便利関数
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end); fin()
def prin(stop=False,sep=" ",end="\n",file=sys.stdout):return (lambda*values:printe(*values,sep=sep,end=end)) if stop else (lambda*values:print(*values,sep=sep,end=end,file=file))
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def printYN(f:bool): yes() if f else no()
def fin(f=True): raise solvedException if f else None
## 分割関数
def split(value:str|list,sep:str=" ",func:callable=str) -> list:
    result = []
    if type(value) == list:
        for i in range(len(value)):
            result.append(split(value[i],sep))
        return result
    else:
        if sep in value:
            for i in value.split(sep):
                result.append(func(i))
        else:
            result.append(func(value))
        return result
## 入力受け取り用
def input():return(sys.stdin.readline()).rstrip() #入力定数倍
def splitS(value:str|list,sep:str=" ")->str:return split(value,sep)[0] #文字列・分割して最初
def splitN(value:str|list,sep:str=" ")->int:return split(value,sep,int)[0] # 整数・分割して最初
def splitB(value:str|list,sep:str=" ")->list:return list(split(value,sep)) # 文字列・分割してすべて
def splitA(value:str|list,sep:str=" ")->list:return list(split(value,sep,int)) # 整数・分割してすべて

# 例外クラス
class solvedException(Exception): pass # 処理打ち切り例外
class unSolvedExeption(Exception): # 回答未出力例外
    def __init__(description = "解答が出力されていません。"): super().__init__(description)

# 実行
if __name__ == "__main__":
    case()

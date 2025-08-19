# ABC419c
# 2025-08-16 20:49:27

def main():
    # 関数定義スペース

    def isOK(pos,dist):
        y=pos[0]+dist[0]
        x=pos[1]+dist[1]
        return 0<=y and 0<=x
        ...

    ...    
    # 入力スペース
    R = []
    C = []
    RC = []
    N = int(input())
    for i in range(N):
        r,c = map(lambda x:int(x)-1,input().split())
        R.append(r)
        C.append(c)
        RC.append((r,c))
    ...

    # 処理スペース
    R.sort()
    C.sort()
    y = math.ceil((R[-1]-R[0])/2)+R[0]
    x = math.ceil((C[-1]-C[0])/2)+C[0]
    result = 0
    for i,j in RC:
        result = max(result,max(y-i,x-j))
    print(result)

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
LRUD = [(0, 1), (0, -1), (1, 0), (-1, 0)] + [(-1, -1), (-1, 1), (1, -1), (1, 1)]

# 便利関数定義(超圧縮)
def input(): return (sys.stdin.readline()).rstrip()
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end); fin()
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def printYN(f:bool): yes() if f else no()
def fin(f=True): raise solvedException if f else None

# 例外クラス
class solvedException(Exception): pass # 処理打ち切り例外
class unSolvedExeption(Exception): # 回答未出力例外
    def __init__(description = "解答が出力されていません。"): super().__init__(description)

# 実行
if __name__ == "__main__":
    case()

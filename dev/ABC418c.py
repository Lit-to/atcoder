# ABC418c
# 2025-08-09 20:06:35
def main():
    # 関数定義スペース

    def search(ok:int,ng:int,f:bool)->int: #二分探索原型
        # okは条件を満たす領域の外側
        # ngは条件を満たさない領域の外側
        # fは条件を満たすかどうかの評価関数
            # lambda i:a[i]<x xを含まない最大のiを返す
            # lambda i:a[i]<=x xを含む最大のiを返す
        while 1<abs(ok-ng):
            mid=(ng+ok)//2
            if f(mid):
                ok=mid
            else:
                ng=mid
        return ok

    ...    
    # 入力スペース

    # N = int(input())
    N, Q = map(int,input().split())
    A = list(map(int,input().split()))
    QUERIES = []
    for i in range(Q):
        QUERIES.append(int(input()))
    A.sort()
    ...

    # 処理スペース
    alived = []
    for i in range(1,max(A)+1):
        alived.append(N-search(N-1,-1,lambda x:i<=A[x]))
        pass
    prefixSum = [0]

    for i in range(len(alived)):
        prefixSum.append(prefixSum[-1]+alived[i])

    MXA=max(A)
    for i in range(Q):
        if MXA<QUERIES[i]:
            print(-1)
            continue
        print(prefixSum[QUERIES[i]-1]+1)

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

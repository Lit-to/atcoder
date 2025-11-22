# ABC419d
# 2025-08-16 20:49:27
def main():
    # 関数定義スペース

    def func():
        ...

    ...    
    # 入力スペース

    N, M = map(int,input().split())
    S = list(input())
    T = list(input())
    s = [0]
    LR = []
    Ls = []
    Rs = []
    for i in range(M):
        L, R = map(lambda x:int(x)-1,input().split())
        # LR.append((L,R))
        Ls.append(L)
        Rs.append(R)
    ...

    # 処理スペース
    result = []
    # LR.sort()
    Ls.sort(reverse=True)
    Rs.sort(reverse=True)
    j = 0
    count = 0
    for i in range(N):
        while Ls and Ls[-1] == i:
            Ls.pop()
            count+=1
        result.append((S,T)[count%2][i])
        while Rs and Rs[-1] == i:
            Rs.pop()
            count-=1
        
        # while j<M and L[j] == i:
            # count+=1
            # queue.append(LR[j][1])
            # j+=1
        # while j<M and R[j] == i:
            # queue.popleft()
            # count-=1
        pass
    print(*result,sep="")




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

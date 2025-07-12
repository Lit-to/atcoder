# ABC323C 
def main():
    # 関数定義スペース

    ...    
    n,m=map(int,input().split())
    a=list(map(int,input().split()))

    mx=0

    flow=dict()
    point=[]
    for i in range(n):
        s=input()
        score=i+1
        flow[i]=list()
        scores=[]
        for j in range(m):
            if s[j]=="o":
                score+=a[j]
            elif s[j]=="x":
                scores.append(a[j])
        mx=max(mx,score)
        point.append(score)
        flow[i]=flow[i]+scores

    score=0

    for i in range(n):
        flow[i].sort()
        flow[i].reverse()
        score=mx-point[i]
        j=0
        while 0<score and j<len(flow[i]):
            score-=flow[i][j]
            j+=1
        print(j)



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

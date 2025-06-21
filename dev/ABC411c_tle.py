# ABC411c
# 2025-06-21 20:51:07
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

# def eval_left(x,i,white_area):
#     if white_area[x] == -1:
#         return False
#     else:
#         return white_area[x]<white_area[i]

# def eval_right(x,i,white_area:list):
#     if white_area[x] == -1:
#         return False
#     else:
#         return white_area[i]<white_area[x]


def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    global A,N,Q
    N, Q = map(int,input().split())
    A = list(map(int,input().split()))
    START=-1
    GOAL=N
    # 処理スペース ================================================================================================Lit_to
    is_black_masu = [False]*N

    for i in range(Q):
        is_black_masu[A[i]-1]= is_black_masu[A[i]-1] != True
        count=0
        j=0
        while j < N:
            r=j+1
            while r<N and is_black_masu[j] and is_black_masu[r]:
                r+=1
            if is_black_masu[j]:
                count+=1
            j = r
        print(count)
        





























# 以下コピペ部分=============================================================
# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict # CPython?
# pypyjit.set_param('max_unroll_recursion=-1')
sys.setrecursionlimit(10**8)
sys.set_int_max_str_digits(0)
dict=defaultdict
# 便利定数定義
ALPHABET="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# ALPHABET="abcdefghijklmnopqrstuvwxyz"
MOD=998244353
MAX=10**18
LRUD=[(0,1),(0,-1),(1,0),(-1,0)]
LURULDRD=[(-1,-1),(-1,1),(1,-1),(1,1)]
# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end);exit()
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def listr(l:list,f=str): return "".join(list(map(f,l)))
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def printYN(f:bool): yes() if f else no()
if __name__=="__main__":
    main()

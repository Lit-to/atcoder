# ABC411c
# 2025-06-21 20:51:07
# 関数定義スペース


def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    global A,N,Q
    N, Q = map(int,input().split())
    A = list(map(int,input().split()))
    START=-1
    GOAL=N
    # 処理スペース ================================================================================================Lit_to
    is_black_masu = [False]*(N+2)
    count = 0 
    for i in range(Q):
        is_black_masu[A[i]] = is_black_masu[A[i]]!=True
        if not is_black_masu[A[i]]: 
            if is_black_masu[A[i]-1] and is_black_masu[A[i]+1]:
                count += 1
            if not is_black_masu[A[i]-1] and not is_black_masu[A[i]+1]:
                count -= 1
        elif is_black_masu[A[i]]:
            if is_black_masu[A[i]-1] and is_black_masu[A[i]+1]:
                count -= 1
            if not is_black_masu[A[i]-1] and not is_black_masu[A[i]+1]:
                count += 1
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

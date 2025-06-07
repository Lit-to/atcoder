# ABC409c
# 2025-06-07 20:26:42
# 関数定義スペース

def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    N, L = map(int,input().split())
    D = list(map(int,input().split()))
    # 処理スペース ================================================================================================Lit_to

    if L%3!=0:
        printe(0)
    ps=[0]
    d=dict(lambda:[])
    for i in range(N-1):
        ps.append((ps[-1]+D[i])%L)


    for i in range(N):
        d[ps[i]].append(i)
    edge=L//3
    result=0
    for i in range(edge+1):
        result+=len(d[i])*len(d[i+edge])*len(d[i+edge+edge])

    print(result)




















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

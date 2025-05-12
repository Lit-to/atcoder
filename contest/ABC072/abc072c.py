# ABC072C
#
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


def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    N = inp()
    A = inp(tuple)
    # 処理スペース ================================================================================================Lit_to
    mn=min(A)-1
    mx=max(A)+1
    result=0
    for x in range(mn,mx+1):
        ans=0
        for i in range(N):
            ans+=(A[i]-1<=x and x<=A[i]+1)
        result=max(result,ans)
    printe(result)























# 以下コピペ部分=============================================================
# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict # CPython?
# pypyjit.set_param('max_unroll_recursion=-1')
sys.setrecursionlimit(10**8)
sys.set_int_max_str_digits(0)
dict = defaultdict #ビルトイン上書きのため他ライブラリで変な挙動になる可能性あり
# 便利定数定義
ALPHABET="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# ALPHABET="abcdefghijklmnopqrstuvwxyz"
MOD=998244353
MAX=10**18
LRUD=[(0,1),(0,-1),(1,0),(-1,0)]
LURULDRD=[(-1,-1),(-1,1),(1,-1),(1,1)]
# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def inputs(N=0,f=input): return input.split() if N==0 else [f() for _ in range(N)] #N行input()>listにして返却
def inpints(f=tuple,s=None): return f(map(int,input().split())) if s==None else f(map(int,s.split()))  #複数個の整数入力
def inpint(s=None): return int(input()) if s==None else int(s) #単数個の整数入力
def inp(f=None): return inpint(s) if (s:=input()).isdigit() else inpints(tuple) if f==None else inpints(f,s) #1つならint,複数個ならtuple(int)として返却
# def inpints_(f=tuple): return int(input())
def inp(f=None): return int(input()) if f==None else inpints(tuple)#1つならint,複数個ならtuple(int)として返却
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end);exit()
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def listr(l:list,f=str): return "".join(list(map(f,l)))
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def look(pos:tuple,board:list): return board[pos[0]][pos[1]]
def printYN(f:bool): yes() if f else no()
if __name__=="__main__":
    main()

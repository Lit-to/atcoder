# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq,pypyjit
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict #Cpythonでは動かない(importにも多少時間がかかる)
pypyjit.set_param('max_unroll_recursion=-1')
sys.setrecursionlimit(10**8)
sys.set_int_max_str_digits(0)
dict=defaultdict

# 便利定数定義
ALPHABET="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# ALPHABET="abcdefghijklmnopqrstuvwxyz"
MOD=998244353
MAX=10**18

# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def yes(f=None): print("Yes") if (f==None or f) else None; exit() if f!=None else None
def no(f=None): print("No") if (f==None or f) else None;exit() if f!=None else None
def printe(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end); exit() #Cpythonでは動かない
def listr(l:list): return "".join(l)
def debug(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def look(pos:tuple,board:list): return board[pos[0]][pos[1]] #HWボードの(i,j)の値を参照して返す関数
def printYN(f:bool): yes() if f else no()


# 関数定義スペース
def search(ok:int,ng:int,f:bool)->int:
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

# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
N, M = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
# 処理スペース ================================================================================================Lit_to
mn=MAX

A_who_can_eats=[]

for i in range(N):
    if A[i]<=mn:
        A_who_can_eats.append((A[i],i+1))
        mn=A[i]
    else:
        continue

A_who_can_eats.append((0,-1))
N=len(A_who_can_eats)
# A_who_can_eats.reverse()
# debug(A_who_can_eats)

for i in range(M):
    result=search(N,-1,lambda x:A_who_can_eats[x][0]<=B[i])
    print(A_who_can_eats[result][1])



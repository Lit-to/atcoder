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
LRUD=[(0,1),(0,-1),(1,0),(-1,0)]

# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def yes(f=True): print("Yes") if (f) else None; exit() if (f) else None
def no(f=True): print("No") if (f) else None;exit() if (f) else None
def printe(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end); exit() #Cpythonでは動かない
def listr(l:list): return "".join(l)
def debug(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def printYN(f:bool): yes() if f else no()


# 関数定義スペース

# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
# N = int(input())
N, S = map(int,input().split())
A = list(map(int,input().split()))
# S = input()
# S = list(input())
S%=sum(A)
yes(S==0)
# 処理スペース ================================================================================================Lit_to
all=A[0]
r=0
for l in range(N):
    if r<=l:
        r=l+1
        all+=A[r%N]
        yes(all==S)
    while all<S:
        r+=1
        all+=A[r%N]
        yes(all==S)
    all-=A[l%N]
    yes(all==S)

no()


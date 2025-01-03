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

# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
N = int(input())
A = list(map(int,input().split()))
# debug("======output is start======")
# 処理スペース ================================================================================================Lit_to

b=[0]*N
b[N-1]=A[N-1]

for i in range(N-1,0,-1):
    pos=i
    j=1
    r=0
    while pos*j<N:
        r+=b[pos*j-1]
        j+=1
    if r%2==A[i-1]:
        b[i-1]=0
    else:
        b[i-1]=1
result=[]
for i in range(N):
    if b[i]==1:
        result.append(i+1)
print(len(result))
print(*result)



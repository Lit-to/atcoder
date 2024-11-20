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
def yes(): print("Yes"); exit()
def no(): print("No"); exit()
def printe(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end); exit() #Cpythonでは動かない
def listr(l:list): return "".join(l)
def debug(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def printYN(f:bool): yes() if f else no()

# 関数定義スペース

# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
# N = int(input())
N, M = map(int,input().split())
X = list(map(int,input().split()))
A = list(map(int,input().split()))
STONES=[]
for i in range(M):
    STONES.append((X[i],A[i]))
STONES.sort()
# if STONES[-1][0]!=N:
#     STONES.append((N,0))
#     M+=1

# 処理スペース ================================================================================================Lit_to
#x(x+1)//2

if sum(A)!=N:
    printe(-1)
if STONES[0][0]!=1:
    printe(-1)


stone=deque()#スタック運用
current=0
cost=0
for i in range(M-1):
    xi,ai=STONES[i]
    xj,aj=STONES[i+1]
    # stone.append((xi,ai))
    current+=ai
    distance=xj-xi-1#必要な石の数
    current-=1#自分の分も置く必要がある
    if current<distance:
        printe(-1)#無理パターン
    current-=distance
    cost+=(distance)*(distance+1)//2
    if i+1<M:
        cost+=current*(xj-xi)
#右端に行くための処理

xi,ai=STONES[-1]
distance=N-xi
current+=ai
cost+=(distance)*(distance+1)//2
print(cost)


# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq,pypyjit
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict #Cpythonでは動かない(importにも多少時間がかかる)
# pypyjit.set_param('max_unroll_recursion=-1') # ワンチャンはやくなるかも
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
def yes(f=True): print("Yes") if (f) else None
def no(f=True): print("No") if (f) else None
def listr(l:list,f=str): return "".join(list(map(f,l)))
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def printYN(f:bool): yes() if f else no()


# 関数定義スペース

# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
# N = int(input())
N, W = map(int,input().split())
block=[]
for i in range(N):
    block.append(list(map(int,input().split()))+[i+1])
    # block_alive.add(i+1)
block=sorted(block)
Q=int(input())
QUERY=[]
for i in range(Q):
    QUERY.append(list(map(int,input().split()))+[i])

# 処理スペース ================================================================================================Lit_to
board=dict(lambda:deque())
block_alive=dict(lambda:MAX)
for i in block:
    board[i[0]].append((i[1],i[2]))

floor=0
while True:
    target=1
    parallel=[]
    while target<=W:
        if len(board[target])==0:
            break
        y,id=board[target].popleft()
        parallel.append(id)
        floor=max(y,floor)
        target+=1
    if len(parallel)<W:
        break
    for i in parallel:
        block_alive[i]=floor
    floor+=1


for i in QUERY:
    printYN(i[0]<block_alive[i[1]])



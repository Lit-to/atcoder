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
# LRUD=[(0,1,1),(0,-1,1),(1,0,0),(-1,0,0)]
LR=[(0,1,1),(0,-1,1)]
UD=[(1,0,0),(-1,0,0)]
LURULDRD=[(-1,-1),(-1,1),(1,-1),(1,1)]

# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end);exit()
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def listr(l:list,f=str): return "".join(list(map(f,l)))
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def printYN(f:bool): yes() if f else no()


# 関数定義スペース
class priorityQueue():#heapqラッパー
    def __init__(self,l=list()):#インスタンス化
        self.queue=l.copy()
        heapq.heapify(self.queue)
    def __getitem__(self,i):
        return self.queue[i]
    def __len__(self):#かぞえる
        return len(self.queue)
    def __str__(self):#出力用
        return str(self.queue)
    def enq(self,value):#入れる
        return heapq.heappush(self.queue,value)
    def add(self,value):#入れる
        return heapq.heappush(self.queue,value)
    def deq(self):#出す
        return heapq.heappop(self.queue)

def check(i,j,move):
    # global result
    if BOARD[i][j]=="G":
        printe(move)
        # result=min(move,result)
    return BOARD[i][j]!="#"

# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
H, W = map(int,input().split())
BOARD=[]
for i in range(H):
    BOARD.append(list(input()+"#"))
BOARD.append(["#"]*(W+1))
# 処理スペース ================================================================================================Lit_to
for i in range(H):
    for j in range(W):
        if BOARD[i][j]=="S":
            start=(i,j)
            BOARD[i][j]="."

SUB_BOARD=[]
for i in range(H+1):
    SUB_BOARD.append([False]*(W+1))

result=MAX

queue=priorityQueue()
for h,w,next in LR+UD:
    if check(start[0]+h,start[1]+w,1):
        queue.add((1,start[0]+h,start[1]+w,next))
        done=set()
        done.add((start[0]+h,start[1]+w))
        done.add((start[0],start[1]))
        
        while queue:
            amount,i,j,next=queue.deq()
            # next=1の場合は次が縦移動であることを表す
            amount+=1
            if next:
                for k in UD:
                    diffY,diffX,next=k
                    SUB_BOARD[i+diffY][j+diffX]=True
                    if (i+diffY,j+diffX) in done:
                        continue
                    if check(i+diffY,j+diffX,amount):
                        done.add((i+diffY,j+diffX))
                        queue.add((amount,i+diffY,j+diffX,1-next))
            else:
                for k in LR:
                    diffY,diffX,next=k
                    SUB_BOARD[i+diffY][j+diffX]=True
                    if (i+diffY,j+diffX) in done:
                        continue
                    if check(i+diffY,j+diffX,amount):
                        done.add((i+diffY,j+diffX))
                        queue.add((amount,i+diffY,j+diffX,1-next))
    pass
    SUB_BOARD=[]
    for i in range(H+1):
        SUB_BOARD.append([False]*(W+1))


print(-1)


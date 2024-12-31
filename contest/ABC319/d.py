# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq
from collections import defaultdict,deque
dict=defaultdict

# 便利定数定義
ALPHABET="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# ALPHABET="abcdefghijklmnopqrstuvwxyz"
MOD=998244353
MAX=10**18
LRUD=[(0,1),(0,-1),(1,0),(-1,0)]

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
        heapq.heappush(self.queue,value)
    def add(self,value):#入れる
        heapq.heappush(self.queue,value)
    def deq(self):#出す
        return heapq.heappop(self.queue)

# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
N, X, F, S = map(int,input().split())
# 処理スペース ================================================================================================Lit_to
queue=priorityQueue()
queue.enq((0,N,X))
while queue.queue:
    hour,lines,ability=queue.deq()
    if lines<=0:
        printe(hour)
    queue.queue.append((hour+1,lines-ability,max(ability-F,0)))
    queue.enq((hour+3,lines,min(ability+S,X)))






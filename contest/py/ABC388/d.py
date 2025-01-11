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

# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
N = int(input())
# H, W = map(int,input().split())
A = list(map(int,input().split()))
# S = input()
# S = list(input())
# 処理スペース ================================================================================================Lit_to

result=[]
queue=priorityQueue()
give_count=N
for i in range(N):
    give_count-=1

    mine=A[i]+len(queue.queue)
    stone=max(0,mine-give_count)

    queue.add(i+mine)
    while queue.queue and queue.queue[0]<=i:
        queue.deq()
    result.append(stone)

print(*result)


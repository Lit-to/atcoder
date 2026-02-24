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

class queue:

    def __init__(self):
        self.data = []
        self.begin = 0
        self.end = 0

    def __len__(self):
        return self.end - self.begin

    def __str__(self):
        return str(self.data[self.begin:self.end])

    def IsEmpty(self):
        return len(self)==0

    def Enqueue(self,value):
        self.data.append(value)
        self.end += 1

    def Dequeue(self):
        self.begin += 1
    
    def GetFront(self):
        return self.data[self.begin]

    def Rebuild(self):
        return queue(self.data[self.begin():self.end()])


# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to

Q = int(input())
QUERY=[]
for i in range(Q):
    QUERY.append(tuple(map(int,input().split())))
# 処理スペース ================================================================================================Lit_to
queue=[]
first=0
index=0
for i in QUERY:
    if i[0]==1:
        if queue:
            queue.append((sum(queue[-1]),i[1]))
        else:
            queue.append((first,i[1]))
    elif i[0]==2:
        first=sum(queue[index])
        index+=1
    else:
        print(queue[i[1]-1+index][0]-first)
        



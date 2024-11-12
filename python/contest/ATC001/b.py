# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq,pypyjit as pypyjit
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
def yes(): print("Yes"); 
def no(): print("No"); 
def printe(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end); exit() #Cpythonでは動かない
def listr(l:list): return "".join(l)
def debug(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def printYN(f:bool): yes() if f else no()

# 関数定義スペース
class unionFind:
    def __init__(self,n):
        self.par=[-1]*n
    def root(self,i):
        if self.par[i]==-1:
            return i
        else:
            self.par[i]=self.root(self.par[i])
            return self.par[i]
    def unite(self,a,b):
        b,a=self.root(b),self.root(a)
        if a==b:
            return
        self.par[b]=a
    def is_same(self,a,b):
        return self.root(a)==self.root(b)


# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
# N = int(input())
N,Q = map(int,input().split())
QUERY=[]
for i in range(Q):
    P,A,B = map(int,input().split())
    QUERY.append((P,A,B))
# 処理スペース ================================================================================================Lit_to

uf=unionFind(N)

for i in QUERY:
    p,a,b=i
    if p==0:
        uf.unite(a,b)
    else:
        printYN(uf.is_same(a,b))




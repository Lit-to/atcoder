# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq,pypyjit
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict #Cpythonでは動かない(importにも多少時間がかかる)
pypyjit.set_param('max_unroll_recursion=-1')
sys.setrecursionlimit(10**8)
sys.set_int_max_str_digits(0)
dict=defaultdict
#ABC278C
# 便利定数定義
ALPHABET="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# ALPHABET="abcdefghijklmnopqrstuvwxyz"
MOD=998244353
MAX=10**18
RLDU={"R":(0,1),"L":(0,-1),"D":(1,0),"U":(-1,0)}
# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end);exit()
def yes(f=True): print("Yes") if (f) else None
def no(f=True): print("No") if (f) else None
def listr(l:list,f=str): return "".join(list(map(f,l)))
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def printYN(f:bool): yes() if f else no()


# 関数定義スペース

# 入力スペース 
# N = int(input())
H, Q = map(int,input().split())
QUERY=[]
for i in range(Q):
    QUERY.append(tuple(map(int,input().split())))
# 処理スペース 

graph=dict(lambda:set())
for i in QUERY:
    t,a,b=i
    if t==1:
        graph[a].add(b)
    elif t==2:
        if b in graph[a]:
            graph[a].remove(b)
    else:
        printYN(b in graph[a] and a in graph[b])


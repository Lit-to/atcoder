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
Q = int(input())
QUERY=[]
for i in range(Q):
    QUERY.append(tuple(map(int,input().split())))
# 処理スペース ================================================================================================Lit_to

pods=deque()
day=0
for i in range(Q):
    if QUERY[i][0]==1:
        pods.append(day)
    elif QUERY[i][0]==2:
        day+=QUERY[i][1]
    elif QUERY[i][0]==3:
        result=0
        j=0
        while pods:
            if QUERY[i][1]<=day-pods[0]:
                result+=1
                pods.popleft()
            else:
                break
        print(result)







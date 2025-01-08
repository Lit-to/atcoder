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

def devide2_or_3(num,count):
    if c[num]!=-1:
        return c[num]+1,d[num]
    else:
        if num%2==0:
            c[num],d[num]=devide2_or_3(num//2,count)
        elif num%3==0:
            c[num],d[num]=devide2_or_3(num//3,count)
        else:
            c[num],d[num]=-1,num
        return c[num]+1,d[num]

# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
N = int(input())
A = list(map(int,input().split()))
# 処理スペース ================================================================================================Lit_to

c=dict(lambda:-1)
d=dict(lambda:-1)
result=set()
counta=0
for i in range(N):
    count,num=devide2_or_3(A[i],0)
    result.add(num)
    counta+=count
if len(result)==1:
    print(counta)
else:
    print(-1)

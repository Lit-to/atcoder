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
S = list(input())
N = len(S)
# 処理スペース ================================================================================================Lit_to
result=0
for j in range(1,N):
    left=dict(lambda:0)
    right=dict(lambda:0)
    i=0
    while i<j:
        left[S[i]]+=1
        i+=1
    k=j+1
    while k<N:
        right[S[k]]+=1
        k+=1
    for key in left:
        result+=left[key]*right[key]

print(result)



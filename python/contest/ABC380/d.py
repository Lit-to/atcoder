# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq,pypyjit
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict
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
def func(group:int,rank):
    if rank==2:
        return group
    else:
        rank=rank>>1
        if group<rank:
            return func(group,rank)
        elif rank<=group:
            return func(group-rank,rank)+1




# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
S = input()
N = len(S)
Q = int(input())
A = list(map(lambda x: int(x)-1,input().split()))
# 処理スペース ================================================================================================Lit_to
result=[]
for i in A:
    chr=S[i%N]
    if func(i//N,1<<60)%2==0:
        result.append(chr)
    else:
        result.append(chr.swapcase())

print(*result)



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
def yes(f=None): print("Yes") if (f==None or f) else None; exit() if f!=None else None
def no(f=None): print("No") if (f==None or f) else None;exit() if f!=None else None
def printe(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end); exit() #Cpythonでは動かない
def listr(l:list): return "".join(l)
def debug(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def look(pos:tuple,board:list): return board[pos[0]][pos[1]] #HWボードの(i,j)の値を参照して返す関数
def printYN(f:bool): yes() if f else no()


# 関数定義スペース

def enumeration(stack:list,n:int,value:int):
    stack.append(value)
    if n==N-1:
        result.append(stack.copy())
        stack.pop()
        return stack
    for i in range(N+(10*n)+1):
        if M<i+value+10:
            break
        enumeration(stack,n+1,i+value+10)
    stack.pop()


# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
# N = int(input())
N, M = map(int,input().split())
# A = list(map(int,input().split()))
# S = input()
# 処理スペース ================================================================================================Lit_to
result=[]
for i in range(1,M+1):
    enumeration([],0,i)

print(len(result))
for i in result:
    print(*i)
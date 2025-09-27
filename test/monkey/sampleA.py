# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict #Cpythonでは動かない(importにも多少時間がかかる)
sys.setrecursionlimit(10**8)
dict=defaultdict

# 便利定数定義
ALPHABET="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# ALPHABET="abcdefghijklmnopqrstuvwxyz"
MOD=998244353
# MAX=10**9+1

# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def yes(): print("Yes"); exit()
def no(): print("No"); exit()
def printe(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end); exit() #Cpythonでは動かない
def listr(l:list): return "".join(l)
def debug(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def printYN(f:bool): yes() if f else no()

# 関数定義スペース
def search(ok:int,ng:int,f:bool):
    while 1<abs(ok-ng):
        mid=(ok+ng)//2
        if f(mid):
            ok=mid
        else:
            ng=mid
    return ok
def calcMoney(A:list,X:int):
    result=0
    for i in A:
        result+=min(i,X)
    return result
# Lit_to~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#入力スペース
# S = list(input())
# S = input() 
# N = int(input())
N, M = map(int,input().split())
A = list(map(int,input().split()))
# BOARD = [list(input()) for i in range(H)]#文字列のリスト
# BOARD = [list(map(int,input().split())) for i in range(H)]#数値のリスト
# A = map(lambda x:x,sorted(list(map(int,(input().split())))))#数の組み合わせを並び替えて渡す
# Lit_to================================================================================================#処理スペース

if sum(A)<=M:
    printe("infinite")
result=search(-1,max(A)+1,lambda x: calcMoney(A,x)<=M)
if max(A)<=result:
    print("infinite")
else:
    print(result)


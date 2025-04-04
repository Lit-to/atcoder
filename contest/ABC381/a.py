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
def look(pos:tuple,board:list): return board[pos[0]][pos[1]] #HWボードの(i,j)の値を参照して返す関数
def printYN(f:bool): yes() if f else no()


# 関数定義スペース

# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
N = int(input())
# H, W = map(int,input().split())
# A = list(map(int,input().split()))
# S = input()
# S = list(input())
S = list(input())
if N%2==0:
    no()
if S==["/"]:
    yes()
if "/" not in S:
    no()
# BOARD = [list(input()) for i in range(H)]#文字列のリスト
# BOARD = [list(map(int,input().split())) for i in range(H)]#数値のリスト
# A = list(map(lambda x:int(x)-1,input().split())) # 0-indexedで値を取得
# A = map(lambda x:x,sorted(list(map(int,(input().split())))))#数の組み合わせを並び替えて渡す
# debug("======output is start======")
# 処理スペース ================================================================================================Lit_to
center=(N+1)//2

pre=set(list(S[:center-1]))
back=set(list(S[center:]))
if len(pre) == 1 and len(back)==1 and "1" in pre and "2" in back:
    yes()
no()
# if A[center]=="/":
#     pre=set(A[:center])
#     back=set(A[center+1:])
#     if len(pre) == 1 and len(back)==1 and 1 in pre and 2 in back:
#         yes()


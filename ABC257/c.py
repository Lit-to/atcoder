# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq,pypyjit
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict #Cpythonでは動かない(importにも多少時間がかかる)
# pypyjit.set_param('max_unroll_recursion=-1') # ワンチャンはやくなるかも
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
# def test_f(x: int):
#     result = 0
#     for i in range(N):
#         result += ((x <= W[i]) and (S[i] == 1)) or ((W[i] < x) and (S[i] == 0))
#     return result

def test_f(x:int):
    

# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
N = int(input())
S = list(map(int, list(input())))
W = list(map(int, input().split()))
# 処理スペース ================================================================================================Lit_to
ws_marged=[]
count_zero_from_left=[0]
count_one_from_left=[0]
count_zero_from_right=[sum(S)]
count_one_from_right=[sum(S)]

for i in range(N):
    ws_marged.append((W[i],S[i]))
ws_marged.sort()

for i in range(N):
    if S[i]==1:
        count_one_from_left.append(count_one_from_left[-1]+ws_marged[i][0])
        count_one_from_right.append(count_one_from_right[-1]-ws_marged[N-i-1][0])
        count_zero_from_left.append(count_zero_from_left[-1])
        count_zero_from_right.append(count_zero_from_right[-1])
    elif S[i]==0:
        count_one_from_left.append(count_one_from_left[-1])
        count_one_from_right.append(count_one_from_right[-1])
        count_zero_from_left.append(count_zero_from_left[-1]+ws_marged[i][0])
        count_zero_from_right.append(count_zero_from_right[-1]-ws_marged[N-i-1][0])






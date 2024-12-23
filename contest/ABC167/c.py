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
RLDU={"R":(0,1),"L":(0,-1),"D":(1,0),"U":(-1,0)}
# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end);exit()
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def listr(l:list,f=str): return "".join(list(map(f,l)))
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def printYN(f:bool): yes() if f else no()


# 関数定義スペース
# 累積和必要か？？？

# 書籍がi番目まで存在していて、全アルゴの理解度のうちの最小がj以上になるための最低金額を求めるdp評価関数 無理な場合はMAX円≒∞円必要となる。
def calc_min_skill(i,j):
    #ここかけば出来るな！
    pass



# 入力スペース 
N, M, X = map(int,input().split())
A=[None]
C=[0]
for i in range(M):
    temp = map(int,input().split())
    C.append(temp[0])
    A.append(temp[1:])
del temp
# S = list(input())
# 処理スペース 

# 書籍がi番目まで存在していて、全アルゴの理解度のうちの最小がj以上になるための最低金額を求めるdp 無理な場合はMAX円≒∞円必要となる。
dp=[]
for i in range(N+1):
    temp=[]
    for j in range(X+1):
        temp.append(MAX)
    dp.append(temp)

for i in range(1,N+1):
    for j in range(1,X+1):
        dp[i][j]=min(calc_min_skill(i,j),dp[i][j])

print(dp[-1][-1])


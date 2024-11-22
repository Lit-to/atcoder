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
def check11_22(n:int,s:str):
    if n%2==0:
        return False
    if s==["/"]:
        return True
    if "/" not in s:
        return False
    center=(n+1)//2
    pre=set(list(s[:center-1]))
    back=set(list(s[center:]))
    if len(pre) == 1 and len(back)==1 and "1" in pre and "2" in back:
        return True
    return False




# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
N = int(input())
S = list(input())+["0"]
# 処理スペース ================================================================================================Lit_to

slash=[]
for i in range(N):
    if S[i]=="/":
        slash.append(i)

result=0
for i in slash:
    pos=[i-1,i+1]
    count=1
    while True:
        left,right=pos
        if (S[left]=="0" or S[right]=="0") and (S[left]=="/" or S[right]=="/"):
            break
        if not(S[left]=="1" and S[right]=="2"):
            count-=1
            break
        if count!=1 and not(S[left-1]==S[left] and S[right]==S[right+1]):
            break
        pos=[left-1,right+1]
        count+=1
    result=max(result,count)

printe(result*2+1)



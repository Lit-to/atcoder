# EDPCE
# 関数定義スペース

def transition(trans:int,condition:bool,default:int,*param):
    if condition(*param):
        return trans(*param)
    else:
        return default()

def trans(dp,VS,WS,W,i,j):
    cand=MAX
    if j-VS[i-1]<0:
        cand=min(cand,dp[i-1][j])
    elif dp[i-1][j-VS[i-1]]+WS[i-1]<=W:
        cand= min(dp[i-1][j-VS[i-1]]+WS[i-1],cand)
    cand=min(dp[i-1][j],cand)
    return cand

def condition(VS,i,j):
    return True

def default():
    return MAX

def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    # N = int(input())
    N, W = map(int,input().split())
    weights=[]
    values=[]
    for i in range(N):
        w,v=map(int,input().split())
        weights.append(w)
        values.append(v)
    # 処理スペース ================================================================================================Lit_to

    dp =[]
    temp=[0]+[MAX]*(10**3+1)
    for i in range(N+1):
        dp.append(temp.copy())

    for i in range(1,N+1):
        for j in range(1,10**3+1):
            dp[i][j]=transition(lambda i,j:trans(dp,values,weights,W,i,j),lambda i,j:condition(values,i,j),lambda:default(),i,j)
            pass
    pass
    for i in range(N,-1,-1):
        for j in range(10**3+1,-1,-1):
            if dp[i][j]<=W:
                printe(j)























# 以下コピペ部分=============================================================
# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict # CPython?
# pypyjit.set_param('max_unroll_recursion=-1')
sys.setrecursionlimit(10**8)
sys.set_int_max_str_digits(0)
dict=defaultdict
# 便利定数定義
ALPHABET="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# ALPHABET="abcdefghijklmnopqrstuvwxyz"
MOD=998244353
MAX=10**9+1
LRUD=[(0,1),(0,-1),(1,0),(-1,0)]
LURULDRD=[(-1,-1),(-1,1),(1,-1),(1,1)]
# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end);exit()
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def listr(l:list,f=str): return "".join(list(map(f,l)))
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def look(pos:tuple,board:list): return board[pos[0]][pos[1]]
def printYN(f:bool): yes() if f else no()
if __name__=="__main__":
    main()
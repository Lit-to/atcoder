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
MAX=10**18
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


# 関数定義スペース

def runLengthEncode(s=str or list) -> list:#ランレングス圧縮(エンコード)
    l=len(s)
    result=[]
    if l==0:
        return result
    now=[s[0],0]
    for i in range(l):
        if s[i]==now[0]:
            now[1]+=1
        elif s[i]!=now[0]:#更新
            result.append(tuple(now))
            now=[s[i],1]
    result.append(tuple(now))
    return result
def runLengthDecode(data:list): #ランレングス圧縮(デコード)
    result=""
    for i in data:
        result+=i[0]*i[1]
    return result





def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    # N = int(input())
    # H, W = map(int,input().split())
    # A = list(map(int,input().split()))
    S = input()
    N = len(S)
    # 処理スペース ================================================================================================Lit_to
    rl=runLengthEncode(S)
    n=len(rl)
    result=[]
    for i in range(n-1):
        if rl[i][0]=="W" and rl[i+1][0]=="A":
            result.append(("A",1))
            result.append(("C",rl[i][1]))
            rl[i+1]=(rl[i+1][0],rl[i+1][1]-1)
        else:
            result.append(rl[i])
    result.append(rl[n-1])

    for i in result:
        print(i[0]*i[1],end="")
    printe()

if __name__=="__main__":
    main()

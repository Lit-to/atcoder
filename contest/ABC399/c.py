# 関数定義スペース



def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    # N = int(input())
    N, M = map(int,input().split())
    GRAPH=dict(lambda:[])
    for i in range(M):
        u,v=map(int,input().split())
        GRAPH[u].append(v)
        GRAPH[v].append(u)

    # 処理スペース ================================================================================================Lit_to
    result=set()
    checked=[True]*(N+1)
    for i in range(1,N+1):
        stack=[]
        if checked[i]:
            stack.append((-1,i))
        else:
            continue
        done=set()
        done.add(i)
        while stack:
            pare,pos=stack.pop()
            checked[pos]=False
            for j in GRAPH[pos]:
                if j==pare:
                    continue
                elif j in done:
                    result.add((min(pos,j),max(pos,j)))
                else:
                    done.add(j)
                    stack.append((pos,j))

    printe(len(result))


























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
if __name__=="__main__":
    main()

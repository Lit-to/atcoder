# 関数定義スペース

def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    N,M = map(int,input().split())
    GRAPH=dict(lambda:[])
    for i in range(M):
        u,v,w=map(int,input().split())
        GRAPH[u].append((v,w))
        GRAPH[v].append((u,w))
    # 処理スペース ================================================================================================Lit_to
    
    stack=[]
    stack.append((1,0))
    done={1}
    min_cost=MAX
    while stack:
        pos,cost=stack.pop()
        if pos==N:
            min_cost=min(min_cost,cost)
            done.remove(pos)
        for i in GRAPH[pos]:
            if i[0] not in done:
                done.add(i[0])
                stack.append((i[0],cost^i[1]))
    print(min_cost)


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
MAX=10**20
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

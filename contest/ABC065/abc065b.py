# ABC065B
# 関数定義スペース



def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    N = inp()
    A = inputs(N,inp)
    # 処理スペース ================================================================================================Lit_to
    graph=dict(lambda:[])
    for i in range(N):
        graph[i+1].append(A[i])
    done=set()
    stack=[(1,0)]
    while stack:
        pos,cost=stack.pop()
        if pos == 2:
            printe(cost)
        for i in graph[pos]:
            if i not in done:
                stack.append((i,cost+1))
                done.add(i)
    printe(-1)

























# 以下コピペ部分=============================================================
# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict # CPython?
# pypyjit.set_param('max_unroll_recursion=-1')
sys.setrecursionlimit(10**8)
sys.set_int_max_str_digits(0)
dict = defaultdict #ビルトイン上書きのため他ライブラリで変な挙動になる可能性あり
# 便利定数定義
ALPHABET="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# ALPHABET="abcdefghijklmnopqrstuvwxyz"
MOD=998244353
MAX=10**18
LRUD=[(0,1),(0,-1),(1,0),(-1,0)]
LURULDRD=[(-1,-1),(-1,1),(1,-1),(1,1)]
# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def inputs(N=0,f=input): return input.split() if N==0 else [f() for _ in range(N)] #N行input()>listにして返却
def inp(f=tuple): return int(s) if (s:=input()).isdigit() else f(map(int, s.split())) #1つならint,複数個ならtuple(int)として返却
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end);exit()
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def listr(l:list,f=str): return "".join(list(map(f,l)))
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def look(pos:tuple,board:list): return board[pos[0]][pos[1]]
def printYN(f:bool): yes() if f else no()
if __name__=="__main__":
    main()

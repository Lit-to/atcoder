# ABC410D XOR Shortest Walk
# 2025-06-14 20:47:47
# 関数定義スペース

def dfs(cur,xor_value):
    for i in GRAPH[cur]:
        next, weight = i
        next_weight = xor_value^weight
        if next_weight not in graph_set[next]:
            graph_set[next].add(next_weight)
            dfs(next,next_weight)


def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    global N,M,GRAPH
    N, M = map(int,input().split())
    GRAPH = dict(lambda:[])
    for i in range(M):
        A, B, W = map(int,input().split())
        GRAPH[A].append((B,W))
    # 処理スペース ================================================================================================Lit_to
    global graph_set
    graph_set = dict(lambda:set())
    dfs(1,0)
    if 0<len(graph_set[N]):
        print(min(graph_set[N]))
    else:
        print(-1)

























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
def printYN(f:bool): yes() if f else no()
if __name__=="__main__":
    main()

# ABC406D Garbage Removal

def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    H, W, N = map(int,input().split())
    trash_map_1=dict(lambda:set())
    trash_map_2=dict(lambda:set())
    for i in range(N):
        x,y=map(int,input().split())
        trash_map_1[x-1].add(y-1)
        trash_map_2[y-1].add(x-1)

    Q = int(input())
    QUERY=[]
    for i in range(Q):
        q,i=map(int,input().split())
        QUERY.append((q,i))
    # 処理スペース ================================================================================================Lit_to
    debug("<")
    for i in QUERY:
        q,j=i
        if q==1:
            print(len(trash_map_1[j-1]))
            for k in trash_map_1[j-1]:
                trash_map_2[k].discard(j-1)
            del trash_map_1[j-1]
        elif q==2:
            print(len(trash_map_2[j-1]))
            for k in trash_map_2[j-1]:
                trash_map_1[k].discard(j-1)
            del trash_map_2[j-1]
        

























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

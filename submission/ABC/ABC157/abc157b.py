# 関数定義スペース
def check(is_broken):
    for i in range(H):
        if is_broken[i][0] and is_broken[i][1] and is_broken[i][2]:
            yes()
    for i in range(W):
        if is_broken[0][i] and is_broken[1][i] and is_broken[2][i]:
            yes()
    if is_broken[0][0] and is_broken[1][1] and is_broken[2][2]:
        yes()
    if is_broken[0][2] and is_broken[1][1] and is_broken[2][0]:
        yes()
    return False



def main():
    dict=defaultdict
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    global H,W
    H, W = 3,3
    
    CARD=inputs(H,inp)
    N = inp()
    QUERY=inputs(N,inp)
    # 処理スペース ================================================================================================Lit_to
    is_broken=[]
    for i in range(H):
        is_broken.append([False]*W)
    for i in QUERY:
        for j in range(H):
            for k in range(W):
                if CARD[j][k]==i:
                    is_broken[j][k]=True
    check(is_broken)
    no()
    























# 以下コピペ部分=============================================================
# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict # CPython?
# pypyjit.set_param('max_unroll_recursion=-1')
sys.setrecursionlimit(10**8)
sys.set_int_max_str_digits(0)
# 便利定数定義
ALPHABET="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# ALPHABET="abcdefghijklmnopqrstuvwxyz"
MOD=998244353
MAX=10**18
LRUD=[(0,1),(0,-1),(1,0),(-1,0)]
LURULDRD=[(-1,-1),(-1,1),(1,-1),(1,1)]
# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def inputs(N:int=0,f=input): return [f() for _ in range(N)] #N行input()>listにして返却
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

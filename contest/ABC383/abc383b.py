# ABC383B Humidifier 2
# 関数定義スペース



def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    H,W,D = inp()
    BOARD = listin(H,lambda:list(input()+"#"))
    BOARD.append(["#"]*(W+1))
    # 処理スペース ================================================================================================Lit_to
    result=0
    for i in range(H):
        for j in range(W):
            if BOARD[i][j]!=".":
                continue
            for k in range(H):
                for l in range(W):
                    if BOARD[k][l]!=".":
                        continue
                    cells=0
                    for m in range(H):
                        for n in range(W):
                            if BOARD[m][n]!=".":
                                continue
                            cells+=(abs(i-m)+abs(j-n)<=D)or(abs(k-m)+abs(l-n)<=D)
                    result=max(cells,result)
    print(result)























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
def listin(N=0,f=lambda:input().split()): return f() if N==0 else [f() for _ in range(N)] # N回fを実行してlistに入れる関数1回の場合はlistにしない
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

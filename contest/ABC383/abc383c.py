# ABC383C Humidifier 3
# 関数定義スペース


def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    H,W,D = inp()
    BOARD = inputb(H,W,"#")
    # 処理スペース ================================================================================================Lit_to

    queue=deque()
    done=set()
    for i in range(H):
        for j in range(W):
            if BOARD[i][j]=="H":
                queue.append(((i,j),D))
                done.add((i,j))

    result=0
    while queue:
        pos,cost=queue.popleft()
        assert look(pos,BOARD)=="." or look(pos,BOARD)=="H"
        result+=1
        if cost<=0:
            continue
        for i in LRUD:
            new_pos=pos[0]+i[0],pos[1]+i[1]
            if new_pos not in done:
                if look(new_pos,BOARD) in {".","H"}:
                    queue.append((new_pos,cost-1))
                    done.add(new_pos)
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
def inputb(height:int,weight:int=-1,atfield:str="#"): return listin(height,lambda:list(input()+atfield))+[[atfield]*(weight+1)] if 0<weight else listin(height,lambda:list(input()))
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end);exit()
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def listr(l:list,f=str): return "".join(list(map(f,l)))
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def look(pos:tuple,board:list): return board[pos[0]][pos[1]]
def place(pos:tuple,board:list,value:any): board[pos[0]][pos[1]]=value
def printYN(f:bool): yes() if f else no()
if __name__=="__main__":
    main()

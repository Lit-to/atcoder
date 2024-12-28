# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq,pypyjit
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict #Cpythonでは動かない(importにも多少時間がかかる)
pypyjit.set_param('max_unroll_recursion=-1')
sys.setrecursionlimit(10**8)
sys.set_int_max_str_digits(0)
dict=defaultdict

# 便利定数定義
ALPHABET="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# ALPHABET="abcdefghijklmnopqrstuvwxyz"
MOD=998244353
MAX=10**18
LRUD=[(0,1),(0,-1),(1,0),(-1,0)]

# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end);exit()
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def listr(l:list,f=str): return "".join(list(map(f,l)))
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def printYN(f:bool): yes() if f else no()


# 関数定義スペース
def compression(A:list)->list:#座標圧縮：配列の座圧(配列を渡して圧縮した座標を返す)
    B=sorted(list(set(A.copy())))#BにAのコピーをし、重複を消し、ソートしたもの
    result=[]#結果となるべき配列
    for i in A:
        result.append(index(B,i))#Aの要素がBのうち何番目にあたるかを返す
    return result
def index(a:list,i:int)->int: #簡易二分探索
    #二分探索で配列の中のiが何番目にあるかを返す
    f=lambda x: a[x]<=i
    ok=-1
    ng=len(a)
    while 1<abs(ok-ng):
        mid=(ng+ok)//2
        if f(mid):
            ok=mid
        else:
            ng=mid
    else:
        return ok


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

class RotateArray: #二次元配列の回転
    ## 時計回りに90度
    def rotate90(grid):
        return [list(g) for g in zip(*grid[::-1])]
    ## 反時計回りに90度
    def rotate_reverse90(grid):
        return [list(g) for g in zip(*grid)][::-1]
    ## 180度
    def rotate180(grid):
        return [list(g)[::-1] for g in grid[::-1]]
    ## 横軸に線対称
    def flip_by_holizontal(grid):
        return [list(g) for g in grid[::-1]]
    ## 縦軸に線対称
    def flip_by_vertical(grid):
        return [list(g)[::-1] for g in grid]

def check(h,w,board):
    for i in range(h):
        write="L"
        for j in range(w):
            if board[i][j]=="L":
                if write!="L":
                    board[i][j]=write
                    pass
            elif board[i][j]=="B":
                if write=="W":
                    return False
                else:
                    write="B"
            else:
                write="W"
    return True
# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
# N = int(input())
N, M = map(int,input().split())
X=[]
Y=[]
C=[]
for i in range(M):
    x,y,c=input().split()
    X.append(int(x))
    Y.append(int(y))
    C.append(c)
X=compression(X)
Y=compression(Y)
# S = list(input())
# 処理スペース ================================================================================================Lit_to
# print(*X)
# print(*Y)
# print(*C)

# board=Board(max(Y)+1,max(X)+1,lambda x:["L"]*(max(X)+1),can_loop=True)
board=[]
H=max(Y)+1
W=max(X)+1
for i in range(H):
    board.append(["L"]*(W))



for i in range(M):
    board[Y[i]][X[i]]=C[i]

no(check(H,W,board)==False)

board=RotateArray.rotate90(board)

no(check(W,H,board)==False)

yes()



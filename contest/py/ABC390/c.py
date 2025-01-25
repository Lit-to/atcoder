# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq,pypyjit
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict #Cpythonでは動かない(importにも多少時間がかかる)
# pypyjit.set_param('max_unroll_recursion=-1') # ワンチャンはやくなるかも
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
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def printYN(f:bool): yes() if f else no()


# 関数定義スペース
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

def count_row(row):
    rl=runLengthEncode(row)
    sep=0
    result_min=0
    result_max=0
    for j in rl:
        if j[0]==".":
            sep+=1
        elif j[0]=="?" and sep:
            result_max+=j[1]
        else:
            if sep==0:
                sep+=1
            if sep==1:
                result_min+=j[1]
                result_max+=j[1]
            # if 2<=sep

    return (result_min,result_max)

def is_accepted(board,h):
    left=-1
    right=MAX
    for i in range(h):
        l,r=count_row(board[i])
        left=max(l,left)
        right=min(r,right)
    return left<=right



# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
H, W = map(int,input().split())
BOARD=[]
for i in range(H):
    BOARD.append(list(input()))
# 処理スペース ================================================================================================Lit_to


no(is_accepted(BOARD,H)==False)
RotateArray.rotate90(BOARD)
no(is_accepted(BOARD,W)==False)
yes()

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

def look_s(pos):
    return BOARD_S[pos[0]][pos[1]]
def look_t(pos):
    return BOARD_T[pos[0]][pos[1]]

def check(pos):
    for k in range(M):
        for l in range(M):
            if look_s((pos[0]+k,pos[1]+l))==look_t((k,l)):
                continue
            else:
                return False
    return True



# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
N, M = map(int,input().split())
BOARD_S=[]
for i in range(N):
    BOARD_S.append(list(input()))
BOARD_T=[]
for i in range(M):
    BOARD_T.append(list(input()))
# 処理スペース ================================================================================================Lit_to

for i in range(N):
    if N<i+M:
        break
    for j in range(N):
        if N<j+M:
            break
        if check((i,j)):
            printe(i+1,j+1)




# 関数定義スペース



def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    N = int(input())
    # H, W = map(int,input().split())
    A = list(map(int,input().split()))
    # S = input()
    # S = list(input())
    # 処理スペース ================================================================================================Lit_to
    
    left_to_right=[]
    count_set=set()
    for i in range(N):
        count_set.add(A[i])
        left_to_right.append(len(count_set))

    count_set=set()
    right_to_left=[]
    for i in range(N-1,-1,-1):
        count_set.add(A[i])
        right_to_left.append(len(count_set))
    right_to_left.reverse()

    result=0
    for i in range(N-1):
        result=max(right_to_left[i+1]+left_to_right[i],result)

    print(result)


























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

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


# 関数定義スペース

def parentheses(index,ph,s):
    if ph[s[index+1]]==False:
        res=parentheses(index+1,ph,s)
        no(len(s)<=res)
        no(s[index]!=ph[s[res+1]])
        return res+1
    else:
        no(s[index]!=ph[s[index+1]])
        return index+1




def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    # N = int(input())
    # H, W = map(int,input().split())
    # A = list(map(int,input().split()))
    S = input()
    N = len(S)
    # 処理スペース ================================================================================================Lit_to
    ph=dict()
    ph[")"]="("
    ph["]"]="["
    ph[">"]="<"
    ph["("]=False
    ph["["]=False
    ph["<"]=False
    index=0
    op_={"(","[","<"}
    while index<N:
        if S[index] in op_:
            index=parentheses(index,ph,S)+1
        else:
            no()
    yes()






if __name__=="__main__":
    main()

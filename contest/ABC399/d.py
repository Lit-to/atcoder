# 関数定義スペース
def check(a:list):
    for i in range(len(a)):
        if (i<len(a) and a[i] == a[i+1]) or (0<i and a[i] == a[i-1]):
            continue
        else:
            return False
    return True

def count_pair(a:list):
    count=0
    for i in range(1,len(a)-1,2):
        count+=a[i]==a[i+1]
    return count

def count_incorrect(a:list):
    count=set()
    for i in range(len(a)):
        if i%2==1:
            continue
        else:
            if a[i]!=a[i+1]:
                count.add((min(a[i],a[i+1]),max(a[i],a[i+1])))
    return len(count)


def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    T = int(input())
    CASES=[]
    for i in range(T):
        n = int(input())
        a = tuple(map(int,input().split()))
        CASES.append((n,a))
    del n,a
    # 処理スペース ================================================================================================Lit_to

    for i in CASES:
        A= i[1]
        num_a=count_pair(A)
        num_b=count_incorrect(A)
        print(num_b-num_a)
        debug("^^^^^^^^^^^")


























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

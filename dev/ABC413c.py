# ABC413c
# 2025-07-05 20:52:15
# 関数定義スペース



def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    Q = int(input())
    QUERIES = []
    for i in range(Q):
        QUERIES.append(tuple(map(int,input().split())))
    # 処理スペース ================================================================================================Lit_to

    stack = deque()
    for i in QUERIES:
        if i[0] == 1:
            q,c,x = i
            stack.append((x,c))
        elif i[0] == 2:
            q,k = i
            result = 0
            count = 0 
            while count < k:
                x,c=stack.popleft()
                if count+c<=k:
                    count+=c
                    result+=x*c
                else:
                    new_c = count+c-k
                    stack.appendleft((x,new_c))
                    count+=c-new_c
                    result+=x*(c-new_c)
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
def printYN(f:bool): yes() if f else no()
if __name__=="__main__":
    main()

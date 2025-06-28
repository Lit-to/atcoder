# ABC412c
# 2025-06-28 20:40:38
# 関数定義スペース



def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    T = int(input())
    CASES = []
    for i in range(T):
        N = int(input())
        S = list(map(int,input().split()))
        F = S[0]
        L = S[-1]
        S.sort()
        CASES.append([N,S,F,L])
    # 処理スペース ================================================================================================Lit_to
    for i  in CASES:
        is_skip = False
        N,S,F,L = i
        if L <= F:
            print(2)
            continue
        count = 1
        now_domino = 0
        while not F<S[now_domino]:
            now_domino+=1
        now_domino-=1
        next_domino = now_domino+1
        while True:
            while S[next_domino]<=2*S[now_domino]:
                if S[next_domino] == L:
                    print(count+1)
                    is_skip = True
                    break
                next_domino+=1
            if is_skip:
                break
            if next_domino-1 == now_domino:
                print(-1)
                break
            now_domino = next_domino-1
            count+=1
























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
def yes(f=True): print("Yes") if (f) else None
def no(f=True): print("No") if (f) else None
def listr(l:list,f=str): return "".join(list(map(f,l)))
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def printYN(f:bool): yes() if f else no()
if __name__=="__main__":
    main()

"""

7
8
1 2 3 5 6 8 9 11
8
1 2 3 5 6 8 9 12
8
1 2 3 5 6 8 9 13
8
1 2 3 5 6 13 20 39
9
6 2 3 5 1 6 8 9 13
2
100 1
8
11 9 8 6 5 3 2 1


"""
"""

5
5
6
-1
3
2
2

"""

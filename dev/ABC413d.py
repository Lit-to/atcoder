# ABC413d
# 2025-07-05 20:52:15
# 関数定義スペース

def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    T = int(input())
    CASES = []
    for i in range(T):
        N = int(input())
        A = tuple(map(int,input().split()))
        CASES.append((N,A))
    # 処理スペース ================================================================================================Lit_to

    for i in CASES:
        n,a = i
        b = []
        for j in range(n):
            if a[j] < 0:
                b.append((a[j]*-1,-1))
            else:
                b.append((a[j],1))
        b = sorted(b,key=lambda x:x[0])

        values = set()
        signs = dict(lambda:0)
        for j in range(n):
            values.add(b[j][0])
            signs[b[j][1]]+=1

        if len(values) == 1:
            # 条件1 マイナスが連続で来るか、マイナスプラスが交互にくるか、プラスだけが来るかのいずれかに該当するかチェック
                printYN(abs(signs[1]-signs[-1])<=1 or signs[1] == 0 or signs[-1] == 0)
                continue

        # 条件2 比が一定になっているか
        for j in range(1,n-1):
            if not (b[j-1][0]*b[j-1][1]*b[j+1][0]*b[j+1][1])==(b[j][0]**2):
                no()
                break
        else:
            yes()
        pass



























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

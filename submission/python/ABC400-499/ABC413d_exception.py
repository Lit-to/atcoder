# 関数定義スペース

def main():
    N = int(input())
    A = tuple(map(int,input().split()))

    b = []
    for j in range(N):
        if A[j] < 0:
            b.append((A[j]*-1,-1))
        else:
            b.append((A[j],1))
    b = sorted(b,key=lambda x:x[0])

    values = set()
    signs = dict(lambda:0)
    for j in range(N):
        values.add(b[j][0])
        signs[b[j][1]]+=1

    if len(values) == 1:
        # 条件1 マイナスが連続で来るか、マイナスプラスが交互にくるか、プラスだけが来るかのいずれかに該当するかチェック
            printYN(abs(signs[1]-signs[-1])<=1 or signs[1] == 0 or signs[-1] == 0)

    # 条件2 比が一定になっているか
    for j in range(1,N-1):
        no(not (b[j-1][0]*b[j-1][1]*b[j+1][0]*b[j+1][1])==(b[j][0]**2))
    yes()

















# テストケース中枢処理
def case():
    TESTCASE = int(input()) # テストケース数の指定
    for _ in range(TESTCASE):
        try:
            main()
        except solved:
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
LRUD=[(0,1),(0,-1),(1,0),(-1,0)]
LURULDRD=[(-1,-1),(-1,1),(1,-1),(1,1)]
TESTCASE = 1
# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end);raise solved
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def printYN(f:bool): yes() if f else no()
class solved(Exception): pass

if __name__=="__main__":
    case()

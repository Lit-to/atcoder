# ABC213C
# 2025-07-19 23:34:28
def main():
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

    ...    
    # 入力スペース
    H, W, N = map(int,input().split())
    A = []
    B = []
    AB = []
    for i in range(N):
        AB.append(tuple(map(int,input().split())))
    for i in range(N):
        A.append(AB[i][0])
        B.append(AB[i][1])

    ...

    a = compression(A)
    b = compression(B)
    # 処理スペース
    for i in range(N):
        print(a[i]+1,b[i]+1)






    ...



# テストケース中枢処理
def case():
    TESTCASE = 1
    # TESTCASE = int(input()) # テストケース数の指定
    for _ in range(TESTCASE):
        try:
            main()
        except solvedException:
            continue
        # raise unSolvedExeption


# インポート
import sys, itertools, math, heapq
from collections import defaultdict, deque
from sortedcontainers import SortedSet, SortedList, SortedDict  # CPython?

# 定数・環境設定
sys.setrecursionlimit(10**8)
sys.set_int_max_str_digits(0)
dict = defaultdict
UPPER_ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
LOWER_ALPHABET="abcdefghijklmnopqrstuvwxyz"
MOD = 998244353
MAX = 10**18
LRUD = [(0, 1), (0, -1), (1, 0), (-1, 0)]
LURULDRD = [(-1, -1), (-1, 1), (1, -1), (1, 1)]

# 便利関数定義(超圧縮)
def input(): return (sys.stdin.readline()).rstrip()
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end); fin()
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def printYN(f:bool): yes() if f else no()
def fin(f=True): raise solvedException if f else None

# 例外クラス
class solvedException(Exception): pass # 処理打ち切り例外
class unSolvedExeption(Exception): # 回答未出力例外
    def __init__(description = "解答が出力されていません。"): super().__init__(description)

# 実行
if __name__ == "__main__":
    case()

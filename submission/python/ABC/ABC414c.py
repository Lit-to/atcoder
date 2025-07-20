# ABC414C
# 2025-07-12 20:53:23
import numpy
def main():
    # 関数定義スペース

    def fill_digits(arr,n,i,odd):
        if i==n:
            r = "".join(arr)
            r+=r[::-1][odd:]
            candidate.append(r)
            return
        else:
            for j in range(0+(i==0),10):
                arr[i] = str(j)
                fill_digits(arr,n,i+1,odd)


    # 入力スペース

    A = int(input())
    N = int(input())

    ...

    # 処理スペース
    candidate = []
    for i in range(1,7):
        fill_digits([0]*(i),i,0,True)
        fill_digits([0]*(i),i,0,False)
    result =0
    # candidate_2 = []
    for i in candidate:
        # num=int("".join(i),A)
        num = int(i)
        num_s = str(numpy.base_repr(num,A))
        # num_s=str(num)
        # debug(num)
        if num<=N and num_s==num_s[::-1]:
            # debug(num)
            result+=num
            pass
    # debug(candidate_2)
    # debug(len(candidate_2))
    printe(result)



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
# from sortedcontainers import SortedSet, SortedList, SortedDict  # CPython?

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

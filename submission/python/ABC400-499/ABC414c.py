# ABC414c
# 2025-07-12 20:53:23
def main():
    # 関数定義スペース
    def fill_one_digit(arr,i,j):
        arr[i]=str(j)
        return arr

    def fill_two_digits(arr,pos_i,pos_j,j):
        arr[pos_i]=str(j)
        arr[pos_j]=str(j)
        return arr


    def fill_digit_odd(arr,n,i):
        if i==n//2:
            for j in range(0,A):
                candidate.append(fill_one_digit(arr,i,j).copy())
            return
        else:
            for j in range(0+(i==0),A):
                fill_digit_odd(fill_two_digits(arr,i,n-i-1,j),n,i+1)


    def fill_digit_even(arr,n,i):
        if i == n//2-1:
            for j in range(0,A):
                candidate.append(fill_two_digits(arr,i,n-i-1,j).copy())
            return
        for j in range(0+(i==0),A):
            fill_digit_even(fill_two_digits(arr,i,n-i-1,j),n,i+1)

    # 入力スペース

    A = int(input())
    N = int(input())

    ...

    # 処理スペース
    candidate = []
    for i in range(1,len(str(N))+2):
        if i % 2 == 0:
            fill_digit_even([0]*i,i,0)
        else:
            fill_digit_odd([0]*i,i,0)
    result =0
    # candidate_2 = []
    for i in candidate:
        num=int("".join(i),A)
        num_s=str(num)
        if num<=N and num_s==num_s[::-1]:
            # candidate_2.append("".join(i))
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

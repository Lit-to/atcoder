# ABC15c
# 2025-07-19 20:27:45
def main():
    # 関数定義スペース

    def isDanger(n:int):
        return S[n-1] == 1

    # def hasDrug(n:int,x:int):
        
    ...    
    # 入力スペース
    N = int(input())
    S = tuple(map(int,list(input())))

    ...

    # 処理スペース
    stack = [0]
    finish = 2**N-1
    done=set()
    while stack:
        bin_state = stack.pop()
        state = str.zfill(bin(bin_state)[2:],N)[::-1]
        for i in range(N):
            if state[i] == "0":
                new_bin=bin_state+(2**i)
                if new_bin not in done:
                    done.add(new_bin)
                    if isDanger(new_bin)==False:
                        yes(new_bin == finish)
                        stack.append(new_bin)
    no()
    


    ...



# テストケース中枢処理
def case():
    # TESTCASE = 1
    TESTCASE = int(input()) # テストケース数の指定
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

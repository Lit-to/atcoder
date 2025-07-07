# 標準入力受け取り
INPUT = dict()

def get_input():
    INPUT["N"] = int(input())
    INPUT["H"], INPUT["W"] = map(int, input().split())
    INPUT["A"] = list(map(int, input().split()))
    INPUT["S"] = input()
    INPUT["S"] = list(input())


# 関数定義スペース
def temp():
    ...


# メイン処理フロー
def main():
    ...


# テストケース中枢処理
def case():
    TESTCASE = 1
    # TESTCASE = int(input()) # テストケース数の指定
    for _ in range(TESTCASE):
        try:
            get_input()
            main()
        except solved:
            pass


# インポート(本編はだいたい30行目あたり)
import sys, itertools, math, heapq
from collections import defaultdict, deque
from sortedcontainers import SortedSet, SortedList, SortedDict  # CPython?

# 定数・環境設定
sys.setrecursionlimit(10**8)
sys.set_int_max_str_digits(0)
dict = defaultdict
# pypyjit.set_param('max_unroll_recursion=-1')
ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# ALPHABET="abcdefghijklmnopqrstuvwxyz"
MOD = 998244353
MAX = 10**18
LRUD = [(0, 1), (0, -1), (1, 0), (-1, 0)]
LURULDRD = [(-1, -1), (-1, 1), (1, -1), (1, 1)]

# 便利関数定義(超圧縮)
def input(): return (sys.stdin.readline()).rstrip()
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end);raise solved
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def printYN(f:bool): yes() if f else no()

# 処理打ち切り例外
class solved(Exception): pass

# 実行
if __name__ == "__main__":
    case()

# ABC319C
def main():
    # 関数定義スペース
    def isGakkari(nums:list,i:int):
        if i not in nums:
            return False
        j = nums.index(i)
        if isOpenedBoard[nums[0]] == 1 and isOpenedBoard[nums[1]] == 1 and isOpenedBoard[nums[2]] == 1:
            if BOARD[nums[(j+1)%3]] == BOARD[nums[(j+2)%3]] and BOARD[nums[(j+2)%3]] != BOARD[nums[j]]:
                return True
        return False
    def isGakkariArray(nums:list):
        for i in nums:
            isOpenedBoard[i] = 1
            if isGakkari([0,1,2],i):
                return True
            if isGakkari([3,4,5],i):
                return True
            if isGakkari([6,7,8],i):
                return True
            if isGakkari([0,3,6],i):
                return True
            if isGakkari([1,4,7],i):
                return True
            if isGakkari([2,5,8],i):
                return True
            if isGakkari([0,4,8],i):
                return True
            if isGakkari([2,4,6],i):
                return True
        return False
        ...

    ...    
    # 入力スペース

    BOARD = []
    for i in range(3):
        BOARD+=split(input(),func=lambda x:int(x)-1)
    
    ...

    # 処理スペース
    result = 0
    candidates = itertools.permutations([0,1,2,3,4,5,6,7,8])
    for i in candidates:
        isOpenedBoard = [0,0,0,0,0,0,0,0,0]
        result+=isGakkariArray(i)
    
    print(1-(result/362880))





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

# 各種関数定義(超圧縮)
## 便利関数(1行関数)
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end); fin()
def prin(stop=False,sep=" ",end="\n",file=sys.stdout):return (lambda*values:printe(*values,sep=sep,end=end)) if stop else (lambda*values:print(*values,sep=sep,end=end,file=file))
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def printYN(f:bool): yes() if f else no()
def fin(f=True): raise solvedException if f else None
def listbin(num): return split(bin(num)[2:],"",int)

## ワンライン出来なかったもの
def split(value:str,sep:str=" ",func:callable=str) -> list:
    """
    分割関数
    文字列をスペース区切りで分割する。
    """
    result = []
    if sep == "":
        result = list(value)
    else:
        section = 0
        for i in range(len(value)):
            if value[i] == sep:
                result.append(value[section:i])
                section = i
        if i == 0 or section != i:
            result.append(value[section:])
    for i in range(len(result)):
        result[i] = func(result[i])
    return result

## 入力受け取り用
def input():return(sys.stdin.readline()).rstrip() #入力定数倍

# 例外クラス
class solvedException(Exception): pass # 処理打ち切り例外
class unSolvedExeption(Exception): # 回答未出力例外
    def __init__(description = "解答が出力されていません。"): super().__init__(description)

# 実行
if __name__ == "__main__":
    case()

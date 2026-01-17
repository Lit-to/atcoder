# ABC441E
# template

"""
/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 入力
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 *
 * # 具体的なロジック
 *
 *
 *
 *
 *
 * # 出力
 *
 *
 */
"""

def main():
    # 関数定義スペース

    ...    

    # 入力スペース
    """
    入力受け取り例
    
    H, W = map(int,input().split())
    A = list(map(int,input().split()))
    """
    N = int(input())
    S = list(input())
    a_count = []
    b_count = []
    c_count = []
    for i in range(N):
        if S[i]=="A":
            a_count.append(1)
            b_count.append(0)
            c_count.append(0)
        if S[i]=="B":
            a_count.append(0)
            b_count.append(1)
            c_count.append(0)
        if S[i]=="C":
            a_count.append(0)
            b_count.append(0)
            c_count.append(1)
    a_ps:prefix_sum = prefix_sum(a_count)
    b_ps:prefix_sum = prefix_sum(b_count)
    result = 0
    for l in range(N):
        for r in range(l,N):
            result += b_ps.get_sum(l,r+1)<a_ps.get_sum(l,r+1)
    print(result)




    ...

    # 処理スペース






    ...

# テンプレートコピペエリア
class prefix_sum():
    """
    累積和クラス
    """
    def __init__(self, value: list, reverse: bool = False):
        """
        コンストラクタ
        累積和の事前計算を行う

        Args:
            -  value (list): 求めたい値配列
            -  reverse (bool, optional): 反転するかどうか
        """
        self.__data=[0]
        for i in value:
            self.__data.append(self.__data[-1] + i)
        self.__data.reverse if reverse else None
        self.__data = tuple(self.__data)
    def get_sum(self, left: int, right: int):
        """
        配列のlからrまでの総和を求める。
        -  半開区間[0,r)の総和-[0,l)の総和の差を取得する。

        Args:
            -  left (int): 左端 0-origin
            -  right (int): 右端 0-origin

        Returns:
            -  int: 総和の結果
        """
        return self.__data[right] - self.__data[left]


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

# 各種関数定義
## 便利関数
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end); fin()
def prin(stop=False,sep=" ",end="\n",file=sys.stdout):return (lambda*values:printe(*values,sep=sep,end=end)) if stop else (lambda*values:print(*values,sep=sep,end=end,file=file))
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def printYN(f:bool): yes() if f else no()
def fin(f=True): raise solvedException if f else None
def listbin(num): return split(bin(num)[2:],"",int)

## 分割関数
def split(value:str,sep:str=" ",func:callable=str) -> list:
    """
    分割関数
    文字列をスペース区切りで分割する。
    """
    result = []
    section = 0
    for i in range(len(value)):
        if value[i] == sep:
            result.append(func(value[section:i]))
            section = i
    if i == 0:
        result.append(func(value[section:]))
    elif section != i:
        result.append(func(value[section+1:]))
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

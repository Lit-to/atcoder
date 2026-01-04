# ABC185c

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
    
    # N = split(input(),func=int)[0]
    # H, W = split(input(),func=int)
    # A = split(input(),func=int)
    # S = split(input())[0]
    """


    ...

    # 処理スペース
    print(lit_math.combination(int(input())-1,11))
    ...

# テンプレートコピペエリア

import math
class lit_math:
    def factorial(n: int) -> int:
        """
        n!の結果を返す。

        より具体的には整数nの階乗の値を返す。

        Args:
            -  n(int):nの値

        Returns:
            -  int: 計算結果
        """
        return lit_math.permutation(n, n)

    def permutation(n: int, k: int) -> int:
        """
        nPkの値を返す。
        より具体的にはn個の整数からk個を順番に並べられる通り数を返す。

        Args:
            -  n(int):nの値
            -  k(int):kの値

        Returns:
            -  int: 計算結果
        """
        result = 1
        for i in range(n, n - k, -1):
            result *= i
        return result

    def combination(n: int, k: int) -> int:
        """
        nCkの値を返す。
        より具体的にはn個の整数からk個を選ぶ組み合わせ数を返す。

        Args:
            -  n(int):nの値
            -  k(int):kの値

        Returns:
            -  int: 計算結果
        """
        return lit_math.permutation(n, k) // lit_math.factorial(k)

    def gcd(value_a: int, value_b: int) -> int:
        """互除法で最大公約数を求める関数

        Args:
            -  value_a (int): 求めたい値A
            -  value_b (int): 求めたい値B

        Returns:
            -  int: AとBの最大公約数
        """
        if value_a < value_b:
            value_a, value_b, value_b, value_a
        while value_b != 0:
            temp = value_b
            value_b = value_a % value_b
            value_a = temp
        return value_a

    def prime(num:int) -> list:
        """素因数分解の結果を返す
        ※利用するためには import mathが必須

        Args:
            -  num (int): 合成数または素数

        Returns:
            -  list: 分解した素数を返す
        """
        result=[]
        while num%2==0:
            num//=2
            result.append(2)
        c=3
        while c<=math.sqrt(num):
            if num%c==0:
                num//=c
                result.append(c)
            else:
                c+=2
        if num!=1:
            result.append(num)
        return result



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

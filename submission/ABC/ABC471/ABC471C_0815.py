# ABC471C
# template
import math


class LitUtility:
    def Search(ok:int,ng:int,f:bool)->int:
        """二分探索を行う関数
        単調増加の範囲においてokのうちいちばんngに近いものの値を返す
        利用例:
        -  lambda i:a[i]<x xを含まない最大のiを返す
        -  lambda i:a[i]<=x xを含む最大のiを返す

        Args:
            -  ok (int): 評価関数fに渡したときに必ずTrueを返すことが保証されている値
            -  ng (int): 評価関数fに渡したときに必ずFalseを返すことが保証されている値
            -  f (bool): 評価関数(引数1/戻り値bool)

        Returns:
            -  int: 結果
        """
        while 1<abs(ok-ng):
            mid=(ng+ok)//2
            if f(mid):
                ok=mid
            else:
                ng=mid
        return ok

    def Compression(A: list) -> list:
        """座標圧縮
        座標を左上に詰める。
        Aをコピー、重複を消し、ソートする。

        Args:
            -  A (list): 圧縮する配列が入ったリスト

        Returns:
            -  list: 圧縮結果
        """
        B = sorted(list(set(A.copy())))
        result = []  # 結果となるべき配列
        for i in A:
            result.append(LitUtility.Index(B, i))  # Aの要素がBのうち何番目にあたるかを返す
        return result


    def Index(a: list, i: int) -> int:  # 簡易二分探索
        # 二分探索で配列の中のiが何番目にあるかを返す
        # →二分探索モジュールと同様のためドキュメント不在
        f = lambda x: a[x] <= i
        ok = -1
        ng = len(a)
        while 1 < abs(ok - ng):
            mid = (ng + ok) // 2
            if f(mid):
                ok = mid
            else:
                ng = mid
        else:
            return ok
    def Factorial(n: int) -> int:
        """
        n!の結果を返す。

        より具体的には整数nの階乗の値を返す。

        Args:
            -  n(int):nの値

        Returns:
            -  int: 計算結果
        """
        return LitUtility.Permutation(n, n)

    def Permutation(n: int, k: int) -> int:
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

    def Combination(n: int, k: int) -> int:
        """
        nCkの値を返す。
        より具体的にはn個の整数からk個を選ぶ組み合わせ数を返す。

        Args:
            -  n(int):nの値
            -  k(int):kの値

        Returns:
            -  int: 計算結果
        """
        return LitUtility.Permutation(n, k) // LitUtility.Factorial(k)

    def CalcGCD(value_a: int, value_b: int) -> int:
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

    def Prime(num:int) -> list:
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



def main():
    # 関数定義スペース

    ...    

    # 入力スペース
    """
    入力受け取り例

    S = im.input()
    H,W = im.listIntInput(2)
    """
    N = im.intInput()
    A = im.listIntInput(N)
    sa = SortedList(A)
    pos = 0
    posIndex = 0
    for i in range(N):
        if 0<=A[i]:
            posIndex = i
            break
    else:
        posIndex = N-1

    s = 0
    for i in range(N):
        leftIndex = LitUtility.Search(posIndex,len(sa),lambda index:sa[posIndex]<=sa[index])
        rightIndex = LitUtility.Search(len(sa),posIndex,lambda index:sa[index]<sa[posIndex])
        newPos = sa[leftIndex]
        newPosIndex = leftIndex
        if (pos-sa[rightIndex]<pos-sa[leftIndex]):
            newPos = sa[rightIndex]
            newPosIndex = rightIndex
        sa.remove(newPos)
        s += abs(pos,newPos)
        pos = newPos
        posIndex = newPosIndex
    print(s)


    ...

    # 処理スペース

    ...

# テンプレートコピペエリア


# テンプレートコピペここまで
#=====================
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
import sys, itertools, math, heapq,builtins
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
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def yesno(f:bool): yes() if f else no()
def fin(f=True): raise solvedException if f else None

## 入力受け取り用
def input():return(sys.stdin.readline()).rstrip() #入力定数倍

"""
入力取得マネージャー
"""
class inputManager:
    __buffer = []
    __index = 0

    @staticmethod
    def input() -> str:
        """
        入力取得関数
        バッファから次の空白･改行文字までの1トークンを取り出す
        バッファが空の場合次の改行文字まで読み出す
        """
        if len(inputManager.__buffer)==0:
            inputManager.__buffer = builtins.input().split()
            inputManager.__index = 0
        result = inputManager.__buffer[inputManager.__index]
        inputManager.__index += 1
        if inputManager.__index==len(inputManager.__buffer):
            inputManager.__buffer = []
        return result
    def intInput() -> int:
        """
        次の数値を取り出す
        数値キャストに失敗すると死ぬ
        """
        return int(inputManager.input())
    def listInput(n:int,f:callable=lambda x:x) -> list:
        """
        n個の入力を配列として返す
        取り出したものを引数に関数fを実行した結果を格納する        

        :param n: 個数
        :type n: int
        :param f: 実行したい関数
        :type f: callable
        """
        result = []
        for i in range(n):
            result.append(f(inputManager.input()))
        return result
    
    def listIntInput(n:int) -> list:
        """
        n個の入力を数値配列として返す
        :param n: 個数
        """ 
        return inputManager.listInput(n,int)

im = inputManager


# 例外クラス
class solvedException(Exception): pass # 処理打ち切り例外
class unSolvedExeption(Exception): # 回答未出力例外
    def __init__(description = "解答が出力されていません。"): super().__init__(description)

# 実行
if __name__ == "__main__":
    case()

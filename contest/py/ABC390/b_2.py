# インポート(本編はだいたい30行目あたり)
from decimal import *
import sys,itertools,math,heapq,pypyjit
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict #Cpythonでは動かない(importにも多少時間がかかる)
# pypyjit.set_param('max_unroll_recursion=-1') # ワンチャンはやくなるかも
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

# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end);exit()
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def listr(l:list,f=str): return "".join(list(map(f,l)))
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def printYN(f:bool): yes() if f else no()


# 関数定義スペース

class fraction:  # 分数
    def __init__(self, numerator: int = 1, denominator: int = 1):
        """
        分数クラスの初期化メソッド
        初期化時に、既約分数にする。

        Args:
            numerator (int, optional): 分子. Defaults to 1.
            denominator (int, optional): 分母. Defaults to 1.

        Raises:
            ValueError: 分母が0の時に発生するエラー。
        """
        if denominator == 0:
            raise ValueError("分母が0です。")

        self.__numerator = numerator
        self.__denominator = denominator

        if numerator != 0:
            self.__approx()

    def __gcd(self,value_a:int,value_b:int)->int:
        """互除法で最大公約数を求める関数
    
        Args:
            value_a (int): 求めたい値A
            value_b (int): 求めたい値B
    
        Returns:
            int: AとBの最大公約数
        """
        value_a,value_b=abs(value_a),abs(value_b)
        if value_a<value_b:
            value_a,value_b,value_b,value_a
        while value_b!=0:
            temp=value_b
            value_b=value_a%value_b
            value_a=temp
        return value_a


    def __approx(self):
        """既約分数を求めるメソッド"""
        gcd = self.__gcd(self.__numerator, self.__denominator)
        self.__numerator //= gcd
        self.__denominator //= gcd

    def get_numerator(self) -> int:
        """分子のgetter

        Returns:
            int: 分子
        """
        return self.__numerator

    def get_denominator(self) -> int:
        """分母のgetter

        Returns:
            int: 分母
        """
        return self.__denominator

    def get_value(self) -> float:
        """分数の小数値を返す

        Returns:
            float: 小数値
        """
        value = self.__numerator / self.__denominator

        if value.is_integer():
            return int(value)
        else:
            return value

    def __str__(self) -> str:
        """str()で呼び出されるメソッド
        分子/分母の形で文字列として返す。

        Returns:
            str: 分数表記の文字列
        """
        return str(self.__numerator) + "/" + str(self.__denominator)

    def __add__(self, value):
        """足し算メソッド
        足し算し、既約分数にした結果を返す。

        Args:
            target (fraction): 足す値となる分数

        Returns:
            fraction: 結果
        """
        return fraction(
            self.__numerator * value.__denominator
            + value.__numerator * self.__denominator,
            self.__denominator * value.__denominator,
        )

    def __sub__(self, value):
        """引き算メソッド
        引き算し、既約分数にした結果を返す。

        Args:
            target (fraction): 引く値となる分数

        Returns:
            fraction: 結果
        """
        return fraction(
            self.__numerator * value.__denominator
            - value.__numerator * self.__denominator,
            self.__denominator * value.__denominator,
        )

    def __mul__(self, value):
        """掛け算メソッド
        掛け算し、既約分数にした結果を返す。

        Args:
            target (fraction): 掛け値となる分数

        Returns:
            fraction: 結果
        """
        return fraction(
            self.__numerator * value.__numerator,
            self.__denominator * value.__denominator,
        )

    def __truediv__(self, value):
        """割り算メソッド
        割り算し、既約分数にした結果を返す。

        Args:
            target (fraction): 割り値となる分数

        Returns:
            fraction: 結果
        """

        return fraction(
            self.__numerator * value.__denominator,
            self.__denominator * value.__numerator,
        )

    def __floordiv__(self, value):
        """割り算メソッド
        __truediv__と同様

        Args:
            value (fraction): 割り値となる分数

        Returns:
            fraction: 結果
        """
        return self.__truediv__(value)

    def __eq__(self, value) -> bool:
        """等価演算子で呼び出されるメソッド
        分母同士、分子同士が等しいときに真となる。

        Args:
            value (fraction): 比較対象

        Returns:
            bool: 演算結果
        """

        return (
            self.__numerator == value.__numerator
            and self.__denominator == value.__denominator
        )

    def __ne__(self, value) -> bool:
        """不等演算子で呼び出されるメソッド
        分母同士、分子同士が等しくないときに真となる。

        Args:
            value (fraction): 比較対象

        Returns:
            bool: 演算結果
        """

        return not self == value

    def __lt__(self, value) -> bool:
        """小なり演算子

        Args:
            value (fraction): 比較対象

        Returns:
            bool: 比較結果
        """
        return (
            self.__numerator * value.__denominator
            < value.__numerator * self.__denominator
        )

    def __gt__(self, value) -> bool:
        """大なり演算子

        Args:
            value (fraction): 比較対象

        Returns:
            bool: 比較結果
        """
        return (
            value.__numerator * self.__denominator
            < self.__numerator * value.__denominator
        )

    def __le__(self, value) -> bool:
        """小なりイコール演算子

        Args:
            value (fraction): 比較対象

        Returns:
            bool: 比較結果
        """
        return not self > value

    def __ge__(self, value) -> bool:
        """大なりイコール演算子

        Args:
            value (fraction): 比較対象

        Returns:
            bool: 比較結果
        """
        return not self < value

    def __iadd__(self, value):
        """加算代入演算子メソッド

        Args:
            value (fraction): 足したい値
        """

        self = self + value
        return self

    def __isub__(self, value):
        """減算代入演算子メソッド

        Args:
            value (fraction): 引きたい値
        """

        self = self - value
        return self

    def __imul__(self, value):
        """乗算代入演算子メソッド

        Args:
            value (fraction): 掛けたい値
        """

        self = self * value
        return self

    def __itruedive__(self, value):
        """除算代入演算子メソッド

        Args:
            value (fraction): 割りたい値
        """

        self = self // value
        return self

    def __ifloordive__(self, value):
        """除算代入演算子メソッド

        Args:
            value (fraction): 割りたい値
        """

        self = self // value
        return self



# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
N = int(input())
# H, W = map(int,input().split())
A = list(map(int,input().split()))
# S = input()
# S = list(input())
# 処理スペース ================================================================================================Lit_to


for i in range(N-2):
    no(fraction(A[i+1],A[i])!=fraction(A[i+2],A[i+1]))
    # no(A[i+1]/A[i] != A[i+2]/A[i+1])

yes()


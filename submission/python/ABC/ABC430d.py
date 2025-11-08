# ABC430c
# 2025-11-01 11:43:38
class prefix_sum(tuple):
    """
    累積和クラス
    tuple: タプルを継承する
    """


    def __init__(self, value: list, reverse: bool = False):
        """
        コンストラクタ
        累積和の事前計算を行う

        Args:
            -  value (list): 求めたい値配列
            -  reverse (bool, optional): 反転するかどうか
        """
        super().__init__()
        self.data=[0]
        for i in value:
            self.data.append(self.data[-1] + i)
        self.data.reverse() if reverse else None
        self.data = tuple(self.data)

    def get_sum(self, left: int, right: int):
        """半開区間[l,r)の総和を取得する。

        Args:
            -  left (int): 左端
            -  right (int): 右端

        Returns:
            -  int: 総和の結果
        """
        return self.data[right] - self.data[left]
def search(ok:int,ng:int,f:bool)->int:
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


def main():
    # 関数定義スペース

    ...    
    # 入力スペース

    N, A, B = split(input(),func=int)
    S = split(input(),"")
    ...

    # 処理スペース

    a = []
    b = []
    for i in range(N):
        a.append(S[i]=="a")
    for i in range(N):
        b.append(S[i]=="b")
    
    a = prefix_sum(a)
    b = prefix_sum(b)
    result= 0
    for l in range(N):
        if not(A<=a.get_sum(l,N)):
            continue
        al=search(N-1,l-1,lambda x:A<=a.get_sum(l,x))
        bl=search(l,N,lambda x:b.get_sum(l,x)<B)
        result+=max(0,bl-al+1)
    print(result)




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

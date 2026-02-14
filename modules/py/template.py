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

    im.input()
    im.intInput()
    im.listInput()
    """


    ...

    # 処理スペース

    ...

# テンプレートコピペエリア


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
def prin(stop=False,sep=" ",end="\n",file=sys.stdout):return (lambda*values:printe(*values,sep=sep,end=end)) if stop else (lambda*values:print(*values,sep=sep,end=end,file=file))
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def printYN(f:bool): yes() if f else no()
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
    def input():
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
    def intInput():
        """
        次の数値を取り出す
        数値キャストに失敗すると死ぬ
        """
        return int(inputManager.input())
    def listInput(n:int,f:callable=lambda x:x):
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

im = inputManager


# 例外クラス
class solvedException(Exception): pass # 処理打ち切り例外
class unSolvedExeption(Exception): # 回答未出力例外
    def __init__(description = "解答が出力されていません。"): super().__init__(description)

# 実行
if __name__ == "__main__":
    case()

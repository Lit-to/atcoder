# ABC438C
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
    
    # N = split(input(),func=int)[0]
    # H, W = split(input(),func=int)
    # A = split(input(),func=int)
    # S = split(input())[0]
    """

    N = split(input(),func=int)[0]
    A = split(input(),func=int)

    ...

    # 処理スペース
    rle = runLengthEncode(A)
    n = len(rle)
    stack = []
    for i in range(n):
        if rle[i][1]%4 == 0:
            continue
        if 0<len(stack) and stack[-1][0] == rle[i][0]:
            if (stack[-1][1]+rle[i][1])%4 == 0:
                stack.pop()
                continue
            else:
                stack[-1][1] = (stack[-1][1]+rle[i][1])%4
        else:
            stack.append([rle[i][0],rle[i][1]%4])
    result = 0
    for i in range(len(stack)):
        result+=stack[i][1]
    print(result)



    ...

# テンプレートコピペエリア

def runLengthEncode(s:str|list) -> list:
    """
    ランレングスエンコードを行う
    要素ごとに分解し、要素と個数のタプル組にする(そのため厳密には圧縮されてはいない)。
    同一の要素がある場合後ろを削除し、手前側の個数に+1する。

    Args:
        -  s (str | list):エンコードしたい文字列 

    Returns:
        -  list: 圧縮後の配列
    """
    l=len(s)
    result=[]
    if l==0:
        return result
    now=[s[0],0]
    for i in range(l):
        if s[i]==now[0]:
            now[1]+=1
        elif s[i]!=now[0]:#更新
            result.append(tuple(now))
            now=[s[i],1]
    result.append(tuple(now))
    return result
def runLengthDecode(data:list)->list:
    """
    ランレングス復号
    要素と個数のタプルが入ったリストをすべての要素で個数個展開する

    Args:
        -  data (list): 要素と個数のタプルが入ったリスト

    Returns:
        -  list: 復号後のリスト
    """
    result=""
    for i in data:
        result+=i[0]*i[1]
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

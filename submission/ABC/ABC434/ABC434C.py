# ABC434C

def main():
    # 関数定義スペース

    def func():
        ...

    ...    
    # 入力スペース

    N, H = split(input(),func=int)
    CHALENGES = []

    for _ in range(N):
        CHALENGES.append(split(input(),func=int))
    ...

    # 処理スペース
    available_l = H
    available_u = H
    now = 0
    for i in range(N):
        t,challenge_l,challenge_u = CHALENGES[i]
        duration = t-now
        available_l = max(available_l-duration,0)
        available_u = available_u+duration
        no(challenge_u < available_l or available_u < challenge_l)
        available_u = min(available_u,challenge_u)
        available_l = max(available_l,challenge_l)
        now = t
    yes()


    

    # stack = [(H,0,0)]
    # # debug("M")
    # while stack:
    #     height,time,index = stack.pop()
    #     # debug(index)
    #     yes(index == len(CHALENGES))
    #     t,l,u = CHALENGES[index]

    #     # Uに移動
    #     inclination = (u-height)/(t-time)
    #     if -1 <= inclination and inclination<=1:
    #         stack.append((u,t,index+1))
    #     elif 1 < inclination:
    #         most = height+(t-time)
    #         if  l<=most and most<=u:
    #             stack.append((most,t,index+1))

    #     # Lに移動
    #     inclination = (l-height)/(t-time)
    #     if -1 <= inclination and inclination<=1:
    #         stack.append((l,t,index+1))
    #     elif inclination < -1:
    #         most = height-(t-time)
    #         if  l<=most and most<=u:
    #             stack.append((most,t,index+1))

    # no()







    ...



# テストケース中枢処理
def case():
    TESTCASE = 1
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

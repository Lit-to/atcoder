# ABC445D
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
    def put(y,x,done:set,y_done:set,x_done:set):
        pos_y = y
        pos_x = x
        h=H-pos_y
        w=W-pos_x
        targetMap_y = Y_MAP[h]
        targetMap_x = X_MAP[w]
        if h not in y_done:
            y_done.add(h)
            for i in range(len(targetMap_y)):
                if targetMap_y[i] not in done:
                    done.add(targetMap_y[i])
                    result[targetMap_y[i]] = (y,pos_x)
                    piece=pieces[targetMap_y[i]]
                    pos_x+=piece[1]
            if len(done)!=N:
                put(pos_y,pos_x,done,y_done,x_done)
        if w not in x_done:
            x_done.add(w)
            for i in range(len(targetMap_x)):
                if targetMap_x[i] not in done:
                    done.add(targetMap_x[i])
                    result[targetMap_x[i]] = (pos_y,x)
                    piece=pieces[targetMap_x[i]]
                    pos_y+=piece[0]
            if len(done)!=N:
                put(pos_y,pos_x,done,y_done,x_done)
    ...    

    # 入力スペース
    """
    入力受け取り例
    
    N = int(input())
    H, W = map(int,input().split())
    A = list(map(int,input().split()))
    S = input()
    """


    ...

    # 処理スペース
    H, W, N = map(int,input().split())
    pieces = []
    
    
    for i in range(N):
        pieces.append(tuple(map(int,input().split())))
    Y_MAP = dict(list)
    X_MAP = dict(list)
    for i in range(N):
        y,x=pieces[i]
        Y_MAP[y].append(i)
        X_MAP[x].append(i)
    
    result = dict()
    put(0,0,set(),set(),set())
    debug("M<")
    for i in range(N):
        print(result[i+1][0]+1,result[i+1][1]+1)




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

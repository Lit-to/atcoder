# AWC0001D
# template

"""
/**
 *方針メモ欄
 *
 * # お気持ち
 *  BFSしたい
 *  ノードの値の差がK以下となるグラフを全部張る
 *  利益についての多始点BFSをする。滞在費の合計がMより大きくなったら探索打ち切り
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
    
    N = int(input())
    A = list(map(int,input().split()))
    S = input()
    """
    AB = []
    N,M,K = map(int,input().split())
    for i in range(N):
        AB.append(tuple(map(int,input().split())))

    ...

    # 処理スペース
    GRAPH = dict(lambda:[])
    for i in range(N):
        for j in range(i+1,N):
            if j-i<=K:
                GRAPH[i].append(j)
                GRAPH[j].append(i)
    result = 0
    for i in range(N):
        done = set()
        stack = list()
        stack.append((i,AB[i][1],AB[i][0]))
        # stack.append()
        done.add(i)
        while stack:
            node,c,v = stack.pop()
            done.add(node)
            result = max(v,result)
            for j in GRAPH[node]:
                if j not in done:
                    n_v,n_c=AB[j]
                    if n_c+c<=M:
                        stack.append((j,n_c+c,n_v+v))
    print(result)








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

# ABC436E
# template
class unionFind:
    """
    Union-Find
    頂点を結合した際に連結する要素の親ノードを1つに統一する
    各頂点の親ノードを高速に返す
    """
    def __init__(self,length:int):
        """
        コンストラクタ

        Args:
            -  n (int):すべて独立したn個ノードとして初期化する
        """
        self.graph=[-1]*length
        self.size =[1]*length

    def unite(self,node_a:int,node_b:int)->None:
        """ノードaとノードbを結合する

        Args:
            -  a (int): 結合したいノード
            -  b (int): 結合したいノード
        """
        node_b,node_a=self.__update_root(node_b),self.__update_root(node_a)
        if node_a==node_b:
            return
        size_a = self.get_size(node_a)
        size_b = self.get_size(node_b)
        if size_a<size_b:
            node_a,node_b=node_b,node_a
            size_a,size_b=size_b,size_a
        self.size[node_a] += size_b
        self.graph[node_b] = node_a
    
    def get_size(self,node:int)->int:
        """
        ノードの属するグループのサイズを求める
        Args:
        -   ノード番号
        Returns:
        -   グループに属するノードの数
        """
        return self.size[self.__update_root(node)]
    
    def is_root(self,node:int)->bool:
        """
        ノードが親ノードかどうかを返す
        Args:
        -   ノード番号
        Returns:
        -   ノードが親かどうか
        """
        return self.graph[node]<0


    def __update_root(self,i:int)->int:
        """親ノードを再帰的に探索する
        途中で見つけた親ノードで各子ノード更新する
        Args:
            -  i (int):探したいノード 
        Returns:
            -  int:親ノード
        """
        if self.is_root(i):
            return i
        else:
            self.graph[i]=self.__update_root(self.graph[i])
            return self.graph[i]


def main():
    # 関数定義スペース

    def func():
        ...

    ...    
    # 入力スペース

    N = int(input())
    A = split(input(),func=int)

    ...

    # 処理スペース
    uf = unionFind(N)
    for i in range(N):
        uf.unite(i,A[i]-1)
    count = []
    for i in range(N):
        if uf.is_root(i):
            count.append(uf.get_size(i))
    result = 0
    for i in range(len(count)):
        result+=math.comb(count[i],2)
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

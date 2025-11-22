# ABC423d
# 2025-09-14 20:46:35
class priority_queue():
    """
    最小値更新ヒープキュー
    ※import heapq必須
    インスタンス化して使えるようにしたもの。
    """
    def __init__(self,l:list=list()):
        """初期化
        インスタンスを生成した際は順番の変更は行われない。
                
        Args:
            -  l (list, optional): 初期値配列(ない場合は空の配列が生成される)
        """
        self.data=l.copy()

        if self.data:
            heapq.heapify(self.data)

    def __len__(self):
        """
        要素数を返すメソッド

        Returns:
            -  int: 要素数
        """
        return len(self.data)

    def __str__(self):#出力用
        """print関数の出力に使うための文字列化

        Returns:
            -  str: self.dataを文字列としたもの

        """
        return str(self.data)

    def enq(self,value:int):#入れる
        """データを挿入し、ヒープ化する。

        Args:
            -  value (int): 挿入する値
        """
        heapq.heappush(self.data,value)

    def add(self,value:int):#入れる
        """データを挿入し、ヒープ化する。

        Args:
            -  value (int): 挿入する値
        """
        self.enq(value)


    def deq(self):#出す
        """要素のうち最小値を取り出す。

        Returns:
            -  int: 取り出した値
        """
        return heapq.heappop(self.data)

    def top(self):
        """要素のうち最小値の値を返す。

        Returns:
            -  int: 最小値
        """
        return self.data[0]


    def empty(self):
        """要素が空かどうかを返す。

        Returns:
            -  bool: 空だった場合True,そうじゃない場合False
        """
        return not bool(self.data)
def main():
    # 関数定義スペース

    def func():
        ...

    ...    
    # 入力スペース

    N, K = splitA(input())
    queue = []
    for i in range(N):
        A,B,C = splitA(input())
        queue.append((A,B,C))
    queue.reverse()
    ...

    # 処理スペース
    eating = 0
    eatingQueue=priority_queue()
    time = 0
    while queue:
        top = queue.pop()
        a,b,c = top
        time=max(time,a)
        while eatingQueue and eatingQueue.top()[0]<=time:
            t,count = eatingQueue.deq()
            eating-=count
        while eatingQueue and not(eating+c <= K):
            t,count = eatingQueue.deq()
            time=t
            eating-=count
        eating+=c
        eatingQueue.enq((time+b,c))
        print(time)
        







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
## 便利関数
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end); fin()
def prin(stop=False,sep=" ",end="\n",file=sys.stdout):return (lambda*values:printe(*values,sep=sep,end=end)) if stop else (lambda*values:print(*values,sep=sep,end=end,file=file))
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def printYN(f:bool): yes() if f else no()
def fin(f=True): raise solvedException if f else None
## 分割関数
def split(value:str|list,sep:str=" ",func:callable=str) -> list:
    result = []
    if type(value) == list:
        for i in range(len(value)):
            result.append(split(value[i],sep))
        return result
    else:
        if sep in value:
            for i in value.split(sep):
                result.append(func(i))
        else:
            result.append(func(value))
        return result
## 入力受け取り用
def input():return(sys.stdin.readline()).rstrip() #入力定数倍
def splitS(value:str|list,sep:str=" ")->str:return split(value,sep)[0] #文字列・分割して最初
def splitN(value:str|list,sep:str=" ")->int:return split(value,sep,int)[0] # 整数・分割して最初
def splitB(value:str|list,sep:str=" ")->list:return list(split(value,sep)) # 文字列・分割してすべて
def splitA(value:str|list,sep:str=" ")->list:return list(split(value,sep,int)) # 整数・分割してすべて

# 例外クラス
class solvedException(Exception): pass # 処理打ち切り例外
class unSolvedExeption(Exception): # 回答未出力例外
    def __init__(description = "解答が出力されていません。"): super().__init__(description)

# 実行
if __name__ == "__main__":
    case()

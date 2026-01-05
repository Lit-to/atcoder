# ABC325D

"""
/**
 *方針メモ欄
 *
 * # お気持ち
 *  印刷可能になった瞬間にそこを印刷して良いのかどうかを判定する
 *  
 *  T,T+Dの順でソート(前から見て貪欲)
 *  L ※以降各要素をTi,Diとする
 *  L ※判断の優先順位は、印刷可能になるタイミング(Ti)が早いほうが先で、中でも印刷終了になるタイミング(Di)が早いほうが優先
 *  
 *  印刷できると判断する方法:Ti<=x<Diを満たすxのいずれかで自分以外の要素が印刷していない場所があること
 *  印刷タイミングは、印刷できる瞬間のうち一番早いとき
 * 
 * # 具体的なロジック
 * Tiリスト:(Ti,Ti+Di)が要素になった配列を作る→実装の都合上逆順ソートする
 * Tiの末尾を抜いてループ
    最後の印字したタイミングよりDiが小さければその値で印字する
    最後に印字したタイミングを最後に印字したタイミング+1かTiの大きいほうで更新する
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
    N = int(input())
    TD = []
    for i in range(N):
        TD.append(tuple(map(int,input().split())))
    ...
    items = []
    for i in range(N):
        items.append((TD[i][0],sum(TD[i]),i))
    items.sort(reverse=True)
    result = 0
    time = 0
    pq = priority_queue()
    while True:
        if len(pq) == 0:
            if len(items)==0:
                break
            time = items[-1][0]
        while 0<len(items) and time==items[-1][0]:
            pq.enq(items[-1][1])
            items.pop()
        if pq.empty()==False:
            result+=1
            pq.deq()
        while pq.empty() == False and pq.top()==time:
            pq.deq()
        time+=1
    print(result)

    # 処理スペース






    ...

# テンプレートコピペエリア
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
class reversed_priority_queue():
    """
    最大値更新ヒープキュー
    最小値更新ヒープキューに-1倍しただけ
    ※ priority_queue必須
    """
    def __init__(self,l:list=list()):
        """初期化
        インスタンスを生成した際は順番の変更は行われない。
                
        Args:
            -  l (list, optional): 初期値配列(ない場合は空の配列が生成される)
        """
        self.data=priority_queue([i*-1 for i in l])

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
        return str(list(map(lambda x:int(x)*-1,str(self.data)[1:-1].split(","))))
        # return str(self.data)

    def enq(self,value:int):#入れる
        """データを挿入し、ヒープ化する。

        Args:
            -  value (int): 挿入する値
        """
        self.data.enq(value*-1)

    def add(self,value:int):#入れる
        """データを挿入し、ヒープ化する。

        Args:
            -  value (int): 挿入する値
        """
        self.enq(value*-1)


    def deq(self):#出す
        """要素のうち最大値を取り出す。

        Returns:
            -  int: 取り出した値
        """
        return self.data.deq()*-1

    def top(self):
        """要素のうち最大値の値を返す。

        Returns:
            -  int: 最大値
        """
        return self.data.top()*-1


    def empty(self):
        """要素が空かどうかを返す。

        Returns:
            -  bool: 空だった場合True,そうじゃない場合False
        """
        return self.data.empty()





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

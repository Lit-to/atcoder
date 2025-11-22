# ABC423c
# 2025-09-14 20:46:35
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


def main():
    # 関数定義スペース

    def func():
        ...

    ...    
    # 入力スペース

    N, R = splitA(input())
    L = splitA(input())

    ...

    # 処理スペース
    L.insert(R,-1)
    l=runLengthEncode(L)
    
    # debug(*l)
    count = 0
    start = False
    for i in l:
        if i[0] ==-1:
            break
        if start:
            if i[0] == 1:
                count+=i[1]*2
            elif i[0] == 0:
                count+=i[1]
        else:   
            if i[0] == 0:
                start = True
                count+=i[1]
    start = False
    for i in l[::-1]:
        if i[0] ==-1:
            break
        if start:
            if i[0] == 1:
                count+=i[1]*2
            elif i[0] == 0:
                count+=i[1]
        else:   
            if i[0] == 0:
                start = True
                count+=i[1]

    printe(count)




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

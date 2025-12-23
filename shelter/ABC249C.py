# ABC249C
def main():
    # 関数定義スペース
    def count(s:list,K:int):
        d = dict(lambda:0)
        for i in list(LOWER_ALPHABET):
            for j in s:
                d[i] += (i in j)
        c = 0
        for i in list(LOWER_ALPHABET):
            c+=d[i] == K
        return c

    ...    

    # 入力スペース
    """
    入力受け取り例
    
    # N = split(input(),func=int)[0]
    # H, W = split(input(),func=int)
    # A = split(input(),func=int)
    # S = split(input())[0]
    """
    N, K = split(input(),func=int)
    S = []
    result = 0
    for i in range(N):
        S.append(list(input()))
    for i in range(2**N):
        s = []
        bit = listbin(i,N)
        debug(*bit)
        for j in range(N):
            if bit[j]==0:
                continue
            else:
                s.append(S[j])
        result = max(result,count(s,K))
    print(result)



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
def listbin(num,digits): return list(map(int,list(bin(num)[2:])))

class bitSearch:
    """
    ビット全探索用クラス
    bitSearch(n)で初期化
    """
    digits:int
    nextValue:int
    lastValue:int
    def __init__(self,n:int):
        """
        """
        self.digits = n
        self.nextValue = 0
        self.lastValue = 1<<n
    def next(self) -> list:
        if self.isFinished():
            return [0]*self.digits
        v = self.nextValue
        digits = [0]*self.digits
        for i in range(self.digits):
            digits[i] = v&1
            v >> 1
        self.nextValue+=1
        return digits
    def isFinished(self)->None:
        return self.lastValue<=self.nextValue
    def reset(self)->None:
        self.nextValue = 1


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

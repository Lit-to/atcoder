# ABC414b
# 2025-07-12 20:53:23
def main():
    # 関数定義スペース

    def runLengthEncode(s=str or list) -> list:#ランレングス圧縮(エンコード)
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
    def runLengthDecode(data:list): #ランレングス圧縮(デコード)
        result=""
        for i in data:
            if 100<int(i[1]):
                return "Too Long"
            result+=i[0]*int(i[1])
            if 100<len(result):
                return "Too Long"
        return result





    ...    
    # 入力スペース

    N = int(input())
    CL =[]
    for i in range(N):
        CL.append(input().split())
    ...
    printe(runLengthDecode(CL))

    # 処理スペース






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

# 便利関数定義(超圧縮)
def input(): return (sys.stdin.readline()).rstrip()
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end); fin()
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def printYN(f:bool): yes() if f else no()
def fin(f=True): raise solvedException if f else None

# 例外クラス
class solvedException(Exception): pass # 処理打ち切り例外
class unSolvedExeption(Exception): # 回答未出力例外
    def __init__(description = "解答が出力されていません。"): super().__init__(description)

# 実行
if __name__ == "__main__":
    case()

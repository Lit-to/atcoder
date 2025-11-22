# ABC420e
# 2025-08-24 20:58:51
class unionFind: #UnionFind
    def __init__(self,n):
        self.par=[-1]*n
    def root(self,i):
        if self.par[i]==-1:
            return i
        else:
            self.par[i]=self.root(self.par[i])
            return self.par[i]
    def unite(self,a,b):
        b,a=self.root(b),self.root(a)
        if a==b:
            return
        self.par[b]=a


def main():
    # 関数定義スペース

    def func():
        ...
    
    def dfs(pos,done):
        for i in tree[pos]:
            if i not in done:
                if nodes[i]:
                    return 1
                done.add(pos)
                r = dfs(i,done)
                done.remove(pos)
                return r
        return 0
    ...    
    # 入力スペース

    # N = int(input())
    N,Q = map(int,input().split())
    QUERIES = []
    for i in range(Q):
        QUERIES.append(tuple(map(int,input().split())))
    ...

    # 処理スペース
    # uf = unionFind(N)
    # nodes = [0]*N
    # for i in QUERIES:
    #     if i[0] == 1:
    #         q,u,v=i
    #         uf.unite(u-1,v-1)
    #     elif i[0] == 2:
    #         q,u = nodes[u-1] = 1
    #     else:
    #         pass

    nodes = [0]*(N+1)
    tree = dict(lambda:[])
    for i in QUERIES:
        if i[0] == 1:
            q,u,v=i
            tree[u].append(v)
            tree[v].append(u)
        elif i[0] == 2:
            q,u = i
            nodes[u] = 1-nodes[u]
        else:
            q,u=i
            if nodes[u]:
                print("Yes")
            elif dfs(u,set()):
                print("Yes")
            else:
                print("No")
            pass




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

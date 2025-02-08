# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict # CPython?
# pypyjit.set_param('max_unroll_recursion=-1')
sys.setrecursionlimit(10**8)
sys.set_int_max_str_digits(0)
dict=defaultdict

# 便利定数定義
ALPHABET="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# ALPHABET="abcdefghijklmnopqrstuvwxyz"
MOD=998244353
MAX=10**18
LRUD=[(0,1),(0,-1),(1,0),(-1,0)]
LURULDRD=[(-1,-1),(-1,1),(1,-1),(1,1)]

# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end);exit()
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def listr(l:list,f=str): return "".join(list(map(f,l)))
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def look(pos:tuple,board:list): return board[pos[0]][pos[1]]
def printYN(f:bool): yes() if f else no()


# 関数定義スペース
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
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    N, M = map(int, input().split())
    SERVERS=[]
    for i in range(M):
        SERVERS.append(tuple(map(int, input().split())))
    # 処理スペース ================================================================================================Lit_to
    d=dict(lambda:set())
    uf=unionFind(N)
    for i in SERVERS:
        uf.unite(i[0],i[1])
        d[i[0]].add(i[1])
        d[i[1]].add(i[0])

    # ufをして、rootを1個にすることと問題文は恐らく同値
    # 自重ループや、同じグループ内で必要のないケーブルを付け替えればよさそう
    # →強連結成分分解とか木の回転をすれば解けそう？



if __name__=="__main__":
    main()

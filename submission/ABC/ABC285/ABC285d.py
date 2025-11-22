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

def search(ok:int,ng:int,f:bool)->int: #二分探索原型
    # okは条件を満たす領域の外側
    # ngは条件を満たさない領域の外側
    # fは条件を満たすかどうかの評価関数
    # lambda i:a[i]<x xを含まない最大のiを返す
    # lambda i:a[i]<=x xを含む最大のiを返す
    while 1<abs(ok-ng):
        mid=(ng+ok)//2
        if f(mid):
            ok=mid
        else:
            ng=mid
    return ok


class factrial:
    def __init__(self, value=1):
        self.pin = -1
        self.__values = []
        self.fact(value)

    def fact(self, value):
        if self.pin == -1:
            self.pin = 0
            self.__values.append(1)
            return 1
        if  self.pin < value:
            for i in range(self.pin+1, value + 1):
                self.__values.append(self.__values[-1] * i)
            self.pin = value
        return self.__get(value)

    def __get(self, index):
        if index <= self.pin:
            return self.__values[index]
        else:
            return -1

    def __str__(self):
        return str(self.__values)


def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    K = int(input())
    # 処理スペース ================================================================================================Lit_to
    k = K
    i = 1
    j=1
    fact=factrial()
    l=fact.fact(j)
    while l != k:
        if l < k:
            j += 1
            l=fact.fact(j)
        else:
            i += 1
            k = K * i
    print(j)

if __name__=="__main__":
    main()

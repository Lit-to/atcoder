# ABC106B

def prime(num:int) -> list:
    """素因数分解の結果を返す
    ※利用するためには import mathが必須
    
    Args:
        num (int): 正の整数

    Returns:
        list: 分解した素数を返す
    """
    result=[]
    while num%2==0:
        num//=2
        result.append(2)
    c=3
    while c<=math.sqrt(num):
        if num%c==0:
            num//=c
            result.append(c)
        else:
            c+=2
    if num!=1:
        result.append(num)
    return result

def divisor(num:int) -> list:
    """約数のリストを返す

    Args:
        num (int): 正の整数

    Returns:
        list: 約数のリスト

    """
    result=[]
    for i in range(num,0,-1):
        if num%i==0:
            result.append(i)
    return result


# 関数定義スペース



def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    N = int(input())
    # 処理スペース ================================================================================================Lit_to
    cnt=0
    for i in range(1,N+1,2):
        a=divisor(i)
        cnt+=len(a)==8    
    print(cnt)


























# 以下コピペ部分=============================================================
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
if __name__=="__main__":
    main()


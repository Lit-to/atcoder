# ABC413d
# 2025-07-05 20:52:15
# 関数定義スペース

def gcd(value_a:int,value_b:int)->int:
    """互除法で最大公約数を求める関数

    Args:
        value_a (int): 求めたい値A
        value_b (int): 求めたい値B

    Returns:
        int: AとBの最大公約数
    """
    if value_a<value_b:
        value_a,value_b,value_b,value_a
    while value_b!=0:
        temp=value_b
        value_b=value_a%value_b
        value_a=temp
    return value_a

def ratio(num1,num2):
    gcds= gcd(num1,num2)
    num1//=gcds
    num2//=gcds
    return num1,num2


def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    T = int(input())
    CASES = []
    for i in range(T):
        N = int(input())
        A = tuple(map(int,input().split()))
        CASES.append((N,A))
    # 処理スペース ================================================================================================Lit_to

    for i in CASES:
        n,a = i
        b = []
        for j in range(n):
            if a[j] < 0:
                b.append((a[j]*-1,-1))
            else:
                b.append((a[j],1))
        b = sorted(b,key=lambda x:x[0])

        # 条件1 マイナスが連続で来るか、マイナスプラスが交互にくるか、プラスだけが来るかのいずれかに該当するかチェック
        is_wa = False
        for j in range(n):
            if b[j%2][1] == b[j][1]:
                continue
            else:
                if j < n-1 and b[j+1][0] == b[j][0]:
                    b[j],b[j+1] = b[j+1],b[j]
            if b[j%2][1] == b[j][1]:
                continue
            else:
                is_wa = True
                break

        if is_wa:
            no()
            continue

        # 条件2 比が一定になっているか
        result = set()
        for j in range(n-1):
            result.add(ratio(b[j][0],b[j+1][0]))
        
        printYN(len(result) == 1)



























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
# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end);exit()
def yes(f=True): print("Yes") if (f) else None
def no(f=True): print("No") if (f) else None
def listr(l:list,f=str): return "".join(list(map(f,l)))
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def printYN(f:bool): yes() if f else no()
if __name__=="__main__":
    main()

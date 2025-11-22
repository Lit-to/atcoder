# abc404d

# 関数定義スペース

def available(bit):
    count=dict(lambda:0)
    for i in range(N):
        if 0<bit[i]:
            for j in ZOOES[i+1]:
                count[j]+=bit[i]
    for j in range(1,M+1):
        if 2<=count[j]:
            continue
        else:
            return False
    return True

def howmuch(bit):
    s=0
    for i in range(N):
        s+=C[i]*bit[i]
    return s

def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    global N,M,C,ANIMALS,K,WANT
    N,M = map(int,input().split())
    WANT = set()
    for i in range(1,M+1):
        WANT.add(i)
    C = list(map(int,input().split()))
    ANIMALS=[]
    K=[]
    for i in range(M):
        z=list(map(int,input().split()))
        K.append(z[0])
        ANIMALS.append(z[1:])
    # 処理スペース ================================================================================================Lit_to
    global ZOOES
    ZOOES=dict(lambda:[])
    for i in range(M):
        for j in ANIMALS[i]:
            ZOOES[j].append(i+1)
    bits=[]
    for i in range(3**N):
        bit=[]
        for _ in range(N):
            bit.append(i%3)
            i//=3
        bits.append(bit)
    # bits.sort()
    result=MAX
    for i in bits:
        if available(i):
            hw=howmuch(i)
            result=min(result,hw)

    print(result)

























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

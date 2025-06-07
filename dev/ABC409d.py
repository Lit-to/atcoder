# ABC409d
# 2025-06-07 20:26:42
# 関数定義スペース



def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    T = int(input())
    TESTCASES=[]
    for i in range(T):
        input()
        s = list(input())
        TESTCASES.append(s)
    # 処理スペース ================================================================================================Lit_to
    for i in TESTCASES:
        s=i
        r=-1
        l=-1
        
        for j in range(len(s)-1):
            if l<0:
                if not(s[j]<s[j+1]):
                    l=j
            else:
                if not(s[j]<s[l]):
                    r=j
                    break
        if l==-1: #もうすでに辞書順最強なので、しゃーなし一番後ろの文字ふたつを入れ替える
            print(*s)
            continue
        else:# 一番後ろの文字がよりもs[l]が弱いので、しゃーなし一番最後に連結する
            if r==-1:
                r=len(s)
        print(*s[:l]+s[l+1:r]+s[l:l+1]+s[r:],sep="") #入れ替え作業後出力



























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
def printYN(f:bool): yes() if f else no()
if __name__=="__main__":
    main()

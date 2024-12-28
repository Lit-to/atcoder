# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq,pypyjit
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict #Cpythonでは動かない(importにも多少時間がかかる)
pypyjit.set_param('max_unroll_recursion=-1')
sys.setrecursionlimit(10**8)
sys.set_int_max_str_digits(0)
dict=defaultdict

# 便利定数定義
ALPHABET="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# ALPHABET="abcdefghijklmnopqrstuvwxyz"
MOD=998244353
MAX=10**18
LRUD=[(0,1),(0,-1),(1,0),(-1,0)]

# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end);exit()
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def listr(l:list,f=str): return "".join(list(map(f,l)))
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def printYN(f:bool): yes() if f else no()


# 関数定義スペース

# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
# N = int(input())
# H, W = map(int,input().split())
# A = list(map(int,input().split()))
# S = input()
s = list(input())
s.reverse()
# 処理スペース ================================================================================================Lit_to
count=0
while s:
    if 2<=len(s) and s[-2:]==["0","0"]:
        s.pop()
        s.pop()
        count+=1
    elif s[-1]=="0":
        s.pop()
        count+=1
    elif s[-1]=="1":
        s.pop()
        count+=1
    elif s[-1]=="2":
        s.pop()
        count+=1
    elif s[-1]=="3":
        s.pop()
        count+=1
    elif s[-1]=="4":
        s.pop()
        count+=1
    elif s[-1]=="5":
        s.pop()
        count+=1
    elif s[-1]=="6":
        s.pop()
        count+=1
    elif s[-1]=="7":
        s.pop()
        count+=1
    elif s[-1]=="8":
        s.pop()
        count+=1
    elif s[-1]=="9":
        s.pop()
        count+=1

print(count)


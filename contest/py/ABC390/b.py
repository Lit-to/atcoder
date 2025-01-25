# インポート(本編はだいたい30行目あたり)
from decimal import *
import sys,itertools,math,heapq,pypyjit
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict #Cpythonでは動かない(importにも多少時間がかかる)
# pypyjit.set_param('max_unroll_recursion=-1') # ワンチャンはやくなるかも
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
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def printYN(f:bool): yes() if f else no()


# 関数定義スペース
import math
class fraction: #分数
    def __init__(self,a=int,b=1):
        if b==0:
            raise ValueError("分母が0です")
        self.molecule=a
        self.denominator=b
        if a!=0:
            self.approx()
    def molecule(self):
        return self.molecule
    def denominator(self):
        return self.denominator
    def devide(self):
        f=self.molecule/self.denominator
        if f.is_integer():
            return int(f)
        else:
            return f
    def __eq__(self,other):
        return self.molecule==other.molecule and self.denominator == other.denominator

    def __add__(self,other):
        return fraction(self.molecule*other.denominator+other.molecule*self.denominator,self.denominator*other.denominator)
    def __sub__(self,other):
        return fraction(self.molecule*other.denominator-other.molecule*self.denominator,self.denominator*other.denominator)
    def __mul__(self,other):
        return fraction(self.molecule*other.molecule,self.denominator*other.denominator)
    def __truediv__(self,other):
        return fraction(self.molecule*other.denominator,self.denominator*other.molecule)
    def __str__(self):
        return str(self.molecule)+"/"+str(self.denominator)
    def is_irreducible(self):
        return True if self.molecule%self.denominator==0 else False
    def prime_factorize(self,n):
        a = []
        if n==1:
            return [1]
        while n % 2 == 0:
            a.append(2)
            n //= 2
        f = 3
        while f * f <= n:
            if n % f == 0:
                a.append(f)
                n //= f
            else:
                f += 2
        if n != 1:
            a.append(n)
        return a
    
    def approx(self):
        a,b=[],[]
        ar,br=1,1
        a=self.prime_factorize(self.molecule)
        b=self.prime_factorize(self.denominator)
        while True:
            if len(a)==0 or len(b)==0:
                ar*=math.prod(a)
                br*=math.prod(b)
                break
            if a[-1]==b[-1]:
                a.pop()
                b.pop()
            elif a[-1]>b[-1]:
                ar*=a.pop()
            elif a[-1]<b[-1]:
                br*=b.pop()

        self.molecule=ar
        self.denominator=br

# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
N = int(input())
# H, W = map(int,input().split())
A = list(map(int,input().split()))
# S = input()
# S = list(input())
# 処理スペース ================================================================================================Lit_to


for i in range(N-2):
    no(fraction(A[i+1],A[i])!=fraction(A[i+2],A[i+1]))
    # no(A[i+1]/A[i] != A[i+2]/A[i+1])

yes()


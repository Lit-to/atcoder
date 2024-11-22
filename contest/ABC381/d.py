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

# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def yes(): print("Yes"); exit()
def no(): print("No"); exit()
def printe(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end); exit() #Cpythonでは動かない
def listr(l:list): return "".join(l)
def debug(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def look(pos:tuple,board:list): return board[pos[0]][pos[1]] #HWボードの(i,j)の値を参照して返す関数
def printYN(f:bool): yes() if f else no()


# 関数定義スペース
def check1122(s:str,n:int):
    if n%2==1:
        return False
    center=n//2
    for i in range(1,center+1):
        if not(s[2*i-2]==s[2*i-1]):
            return False
    d=dict(lambda:0)
    for i in s:
        d[i]+=1
    for i in d:
        if d[i]!=2:
            return False
    return True

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
        result+=i[0]*i[1]
    return result




# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
N = int(input())
A = list(map(int,input().split()))
# 処理スペース ================================================================================================Lit_to

rl=runLengthEncode(A)
q=len(rl)
result=0
count=0
used=set()
d=dict(lambda:0)
for i in range(q):
    if count==0:
        if 2<=rl[i][1]:
            count+=1
            d[rl[i][0]]+=1
    elif rl[i][1]==2 and d[rl[i][0]]<1:
        count+=1
        d[rl[i][0]]+=1
    elif d[rl[i][0]]<2:
        d[rl[i][0]]+=1
        continue
    else:
        keep=False
        if 2<=rl[i][1] not in used:
            keep=True
            count+=1
        result=max(count,result)
        count=0
        d=dict(lambda:0)
        if keep:
            count+=1
            d[rl[i][0]]+=1
result=max(count,result)
print(result*2)


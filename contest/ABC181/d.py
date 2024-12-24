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
RLDU={"R":(0,1),"L":(0,-1),"D":(1,0),"U":(-1,0)}
# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end);exit()
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def listr(l:list,f=str): return "".join(list(map(f,l)))
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def printYN(f:bool): yes() if f else no()


# 関数定義スペース
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

def check(content):
    if len(content)==1:
        return int(content[0])%8==0
    elif len(content)==2:
        return int(content[0]+content[1])%8==0 or int(content[1]+content[0])%8==0
    d=dict(lambda:0)
    for i in content:
        d[i]+=1
    for i in range(3-len(content)):
        d["0"]+=1

    for i in range(1,125):
        eight=i*8
        s=str(eight)
        if 4<len(s):
            break
        for j in range(3-len(s)):
            s="0"+s
        rl=runLengthEncode(sorted(list(s)))
        for i in range(len(rl)):
            if d[rl[i][0]]<rl[i][1]:
                break
        else:
            return True
    return False
# 入力スペース 
S = list(list(input()))

printYN(check(S))








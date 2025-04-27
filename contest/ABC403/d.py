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


def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    N, D = map(int,input().split())
    A = list(map(int,input().split()))
    A.sort()
    # 処理スペース ================================================================================================Lit_to
    mx=max(A)
    mn=min(A)
    B=runLengthEncode(A)
    n=len(B)
    probably_delete=dict(lambda:MAX)
    right=1
    for left in range(n-1):
        if right<=left:
            right=left+1
        section=abs(B[right][0]-B[left][0])
        while section<=D:
            if section == D:
                probably_delete[B[left][0]]=B[left][1]
                probably_delete[B[right][0]]=B[right][1]
                break
            else:
                if n<=right+1:
                    break
                right+=1
                section=abs(B[right][0]-B[left][0])

    dp = [MAX]*N
    n =len(probably_delete)
    # for i in range(n):
    #     dp.append([10**7]*n)
    
    pro_key=probably_delete.keys()
    for i in range(n):
        dp[i]=min(probably_delete[pro_key[i]],probably_delete[pro_key[i]-D])



    # print(min(result))




















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

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
NUMBER=2019
if 0<len(sys.argv) and "FREQUENCY" in sys.argv:
    debug("頻度計測:True")
    class frequency_count:
        """
        出現頻度カウント用クラス
        デバッグ用に、プログラムのある個所が何回実行されるかをカウントする。
        プログラム終了直前に出力する。
        """
        def __init__(self,*args:str,file=sys.stdout):
            """
            コンストラクタ
            defaultdictをdictで上書きしていない場合はここで定義した名前のみ利用可能。

            Args:
                *args(str):キーとなる名前
                file:出力先
            """
            self.existMAX=False
            self.file=file
            assert 0<len(args)
            self.data=dict()
            self.count=len(args)
            for i in range(self.count):
                if args[i]=="MAX":
                    self.MAX=args[i]
                    self.existMAX=True
                self.data[args[i]]=0

        def __getitem__(self,key):
            """
            カウンタ
            self[key]と呼ぶだけで自動的に1回と数える。

            Args:
                key(int) キー
            """
            self.data[key]+=1

        def __del__(self):
            """
            デストラクタ
            プログラム終了時に内容を出力する。
            MAXというキーが存在しない場合は数のみ、する場合はグラフを出力する。
            """
            if self.existMAX==True:
                mx=self.data[self.MAX]
                print("■"*10," :",self.MAX,self.data[self.MAX],file=self.file)
                for i in self.data:
                    count=self.data[i]
                    if mx==count:
                        print("■"*10," :",i,count,file=self.file)
                    elif mx<count:
                        print("■"*11,":",i,count,file=self.file)
                    else:
                        amount=min(10-int((count/mx)*10),0)
                        print("■"*amount+"□"*(10-amount)," :",i,count,file=self.file)
            else:
                for i in self.data:
                    print(i,":",count,file=self.file)
else:
    class frequency_count:
        def __init__(self,*args,file=""):
            pass
        def __getitem__(self,key):
            pass
        def __del__(self):
            pass
# デバッグ用
FREQUENCY_COUNT=frequency_count("MAX","a","b","c",file=sys.stderr)



def prime(num:int) -> list:
    """素因数分解の結果を返す
    ※利用するためには import mathが必須
    
    Args:
        num (int): 合成数または素数

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

def prime(num:int):
    FREQUENCY_COUNT["MAX"]
    result=set()
    while num%2==0:
        FREQUENCY_COUNT["b"]
        num//=2
        result.add(2)
    c=3
    while c<=math.sqrt(num):
        FREQUENCY_COUNT["a"]
        if num%c==0:
            num//=c
            result.add(c)
        else:
            c+=2
    if num!=1:
        result.add(num)
    return result


# 入力スペース 
L, R = map(int,input().split())
three=set()
six=set()
for i in range(L,R):
    if 3 in prime(i):
        three.add(i)
    if 673 in prime(i):
        six.add(i)

if len(three)==0 or len(six)==0:
    no()

print(0)







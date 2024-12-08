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
def yes(f=None): print("Yes") if (f==None or f) else None; exit() if f!=None else None
def no(f=None): print("No") if (f==None or f) else None;exit() if f!=None else None
def printe(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end); exit() #Cpythonでは動かない
def listr(l:list): return "".join(l)
def debug(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def look(pos:tuple,board:list): return board[pos[0]][pos[1]] #HWボードの(i,j)の値を参照して返す関数
def printYN(f:bool): yes() if f else no()


# 関数定義スペース
def search(ok:int,ng:int,f:bool)->int:
    # okは条件を満たす領域の外側
    # ngは条件を満たさない領域の外側
    # fは条件を満たすかどうかの評価関数
        # lambda i:a[i]<x xを含まない最大のiを返す
        # lambda i:a[i]<=x xを含む最大のiを返す
    while 1<abs(ok-ng):
        mid=(ng+ok)//2
        if f(mid):
            ok=mid
        else:
            ng=mid
    return ok

class segmentTree:
    def __init__(self,values,default=-1,rule=lambda x,y:max(x,y)):
        """
        初期化関数 これらのデータをもとにセグメント木を構築する。
        self.rule(x,y)は、x,tのうち優先度が大きいほうの値が返却される関数としてユーザが定義する
        Args:
            values (list) :初期化対象の配列
            default (int) :初期化設定がなかったときの初期値(更新時に一番更新の優先度が低くなる値) デフォルトは-1
            rule (function) :値の更新基準 デフォルトは最大更新 
        Exception:
            ValueError:valuesに空配列が指定された場合
        """
        assert 1<=len(values),"ValueError:'values' are needed at least 1 value."
        self.value_length=len(values)

        self.half_size=self.calc_size()
        
        self.size=self.half_size*2
        
        self.values=[default]*(self.size+1) #1-indexedのための端を追加
        
        self.default=default
        
        self.rule=rule
        
        for i in range(self.value_length):#値の上書き
            self.values[i+self.half_size]=values[i]
        
        self.__struct(2)

    def __struct(self,index:int):
        """
        セグメント木を再帰的に構築する関数
        self.ruleをここで利用する

        Args:
            index (int): 値を代入するインデックス

        Returns:
            _type_: 代入された値を返す
        """
        value=self.default
        if self.size<(index<<1):
            right_value=self.values[index]
            left_value=self.values[index-1]
            value=self.rule(left_value,right_value)
        else:
            right_value=self.__struct(index*2)
            left_value=self.__struct(index*2-1)
            value=self.rule(left_value,right_value)
            self.values[index-1]=value
        return value

    def __str__(self):
        """str()が呼ばれたときの挙動
        """
        return str(self.values)

    def __len__(self):
        """
        len()で呼び出された時の値
        """
        return self.size()

    def calc_size(self):
        """
        セグメント木を構築するためのサイズを計算する。
        完全二分木である必要があるため、2,4,8,16...で一番近いものを選んでサイズを決定する。
        厳密には、(1<=i)を満たす整数のうち、2^iの結果がself.sizeを超える一番小さい値になるように設定する。

        求め方:
            lengthのMSb(1になっているビットのうち、一番左のもの)を求める。
            1をMSb左にビットシフトする。
        """
        length=self.value_length
        if length <=1:
            return 2
        return 1<<self.__calc_msb(length)

    def __calc_msb(self,num:int):
        num-=1
        """
        MSbを求める。
        本来はここをO(logN)で求める方法があるはずだが、ここでは簡便にO(N)で求める。
        ※要修正
        """
        msb=1
        while num!=1:
            msb+=1
            num>>=1
        return msb

    def get_value(self,left:int,right:int):
        """
        (left:right)のうち、self.ruleの優先順位が一番高い値を返す

        Args:
            left (int): 区間のインデックスの左端
            right (int): 区間のインデックスの右端
        """
        assert left<right , "left value needs lower than right"
    
    def update_value(self,index:int,value:int):
        """
        配列のindex番目にvalueを代入し木の更新を行う。

        Args:
            index (int): 代入したい位置を示すインデックス
            value (int): 代入したい値
        """
        index+=self.values
        self.values[index]=value
        NEIGHBOR=[-1,1]
        while index!=0:
            next=index>>1
            diff=NEIGHBOR[index%2==0]
            new_value=self.rule(self.values[index],self.values[index+diff])
            self.values[next]=new_value
            index=next




if __name__=="__main__":
    tree=segmentTree([3,5,7,3,5,7,98,4,3,5,7,45,23,34,22,76])
    segment=[]
    for i in range(tree.size):
        if i==0:
            print(tree.values[1])
            continue
        elif 1==len(set(list(bin(i)[2:]))):
            print(*segment) if segment else segment
            segment=[]
            segment.append(tree.values[i])
        else:
            segment.append(tree.values[i])

    print(tree.values)



# # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
# N, M = map(int,input().split())
# A = list(map(int,input().split()))
# B = list(map(int,input().split()))
# # 処理スペース ================================================================================================Lit_to
# mn=MAX


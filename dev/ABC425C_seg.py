# ABC425c
# 2025-09-27 11:53:55

class segmentTree(list):
    def __init__(self,values,default=-1,rule=lambda x,y:max(x,y)):
        """
        初期化関数 これらのデータをもとにセグメント木を構築する。
        self.__rule(x,y)は、x,tのうち優先度が大きいほうの値が返却される関数としてユーザが定義する
        Args:
            -  values (list) :初期化対象の配列
            -  default (int) :初期化設定がなかったときの初期値(更新時に一番更新の優先度が低くなる値) デフォルトは-1
            -  rule (function) :値の更新基準 デフォルトは最大更新 
        Exception:
            -  ValueError:valuesに空配列が指定された場合
        """
        # super().__init__(values)
        self.__value_length=len(values) # 実際の値の長さ
        self.__center=self.__calc_size() # 完全二分木として表す配列の長さの半分(値が格納できる大きさのうち一番小さい値をiとしたときの2^iで、実際の値が入る部分の長さ)
        self.__size=self.__center*2 # MSbの2倍の長さの配列
        self.__data=[default]*(self.__size+2) #1-indexedのための端を追加
        self.__default=default # 初期値
        self.__rule=rule # 値更新ルール
        
        for i in range(self.__value_length):#値の上書き
            self.__data[i+self.__center]=values[i]
        
        self.__struct(2)

    def __struct(self,index:int)->list:
        """
        セグメント木を再帰的に構築する関数
        self.__ruleをここで利用する

        Args:
            -  index (int): 値を代入するインデックス

        Returns:
            -  list: 代入された値を返す
        """
        value=self.__default
        if self.__size<(index<<1):
            return self.__data[index-1]
        else:
            right_value=self.__struct(index*2)
            left_value=self.__struct(index*2-1)
            value=self.__rule(left_value,right_value)
            self.__data[index-1]=value
        return value

    def __calc_size(self):
        """
        セグメント木を構築するためのサイズを計算する。
        完全二分木である必要があるため、2,4,8,16...で一番近いものを選んでサイズを決定する。
        厳密には、(1<=i)を満たす整数のうち、2^iの結果がself.sizeを超える一番小さい値になるように設定する。

        求め方
            -  lengthのMSb(1になっているビットのうち、一番左のもの)を求める。
            -  1をMSb左にビットシフトする。
        Return:
            -  int:サイズ
        """
        length=self.__value_length
        if length <=1:
            return 2
        return 1<<self.__calc_msb(length)

    def __calc_msb(self,num:int):
        """
        MSbを求める。
        本来はここをO(logN)で求める方法があるはずだが、ここでは簡便にO(N)で求める。
        ※要修正
        """
        num-=1
        msb=0
        while num>0:
            msb+=1
            num>>=1
        return msb

    def __check_rule(self,q_l:int,q_r:int,t_l:int,t_r:int,k:int):
        """
        (q_l,q_r)の区間のうち、(t_l,t_r)と被っている部分のルール結果を返す。
        複数区間にまたがっている場合は区間を狭めて再起呼び出しする。
        Args:
            -  t_l (int): 調査区間の左端
            -  t_r (int): 調査区間の右端
            -  q_l (int): クエリ区間の左端
            -  q_r (int): クエリ区間の右端
            -  k (int): (l,r)の結果が格納されているインデックス

        Returns:
            _type_: 結果
        """
        if q_r<t_l or t_r<=q_l: # 対象外範囲の場合はルール最弱の値を返す
            return self.__default
        elif q_l<=t_l and t_r-1<q_r:#この時点で答えが確定している場合は答えを返す
            return self.__data[k]
        # elif t_l==t_r-1: # lrがぶつかってしまった場合は区間内にいるかどうかをチェック
            # if q_l<=t_r and t_r<=q_r: #区間内の場合は今見える値を返す
            # return self.__data[k]
            # else: #区間外の場合はルール最弱の値を返す
                # return self.__default
        
        # 以下、範囲が調べたい範囲の境界線を踏んでいる場合
        # 今の区間では判断できないので細分して再起呼び出しで判断する
        left=self.__check_rule(q_l,q_r,t_l,(t_l+t_r)//2,2*k) 
        right=self.__check_rule(q_l,q_r,(t_l+t_r)//2+1,t_r,2*k+1)
        return self.__rule(left,right)

    def get_query(self,left:int,right:int):
        """
        (left:right)のうち、self.__ruleの優先順位が一番高い値を返す

        Args:
            -  left (int): 区間のインデックスの左端
            -  right (int): 区間のインデックスの右端
        """
        assert left<right , "left value needs lower than right"
        assert 0<=left , "left value needs more than 0"
        assert right<=self.__value_length , "right value needs lower than max length"
        return self.__check_rule(left+1,right+1,1,self.__center+1,1) #1-indexedに変えてみる


    ### 組み込み系対応関数

    def __len__(self):
        """
        len()が呼び出されたときの関数
        __value_length、つまり初期化時の配列長を返す
        Returns:
            -  int: 配列長
        """
        return self.__value_length
    
    def __str__(self):
        """
        str()が呼び出されたときの関数
        配列をstr()したものを返す

        Returns:
            -  str: 配列をstr()したもの
        """
        return str(self.__data[self.__value_length+1:self.__center+self.__value_length])

    def __getitem__(self,item:slice|int):
        """
        配列にスライスやインデックスの読み出しをする関数
        list[x]のように指定したときに呼び出される
        初期化時の配列(list型)と同様の挙動をする

        Args:
            -  item (slice | int): list[x]のxにあたるインデックス(1-indexed)

        Returns:
            int: 読みだしたデータの内容
        """
        if type(item)==int:
            if 0<=item:
                return self.__data[self.__value_length+item]
            else:
                return self.__data[self.__value_length+self.__center+item]
        else:
            start,stop,step=item.start,item.stop,item.step
            if start==None:
                start=1
            if stop==None:
                stop=self.__value_length
            if step==None:
                step=1
            return self.__data[self.__center+start-1:self.__center+stop-1:step]

    def __setitem__(self,key:int,value:int):
        """
        値の更新を行う

        Args:
            -  key (int): インデックス(1-indexed)
            -  value (int):更新する値 
        """
        self.update(key,value)


    ###セグメント木らしい関数↓

    def update(self,index:int,value:int):
        """
        配列のindex番目にvalueを代入し木の更新を行う。

        Args:
            -  index (int): 代入したい位置を示すインデックス
            -  value (int): 代入したい値
        """
        assert 0<=index<=self.__value_length,"illigal index("+str(index)+")"
        index+=self.__center-1
        self.__data[index]=value
        NEIGHBOR=[-1,1]
        while 2<=index:
            next=index>>1
            diff=NEIGHBOR[index%2==0]
            new_value=self.__rule(self.__data[index],self.__data[index+diff])
            self.__data[next]=new_value
            index=next

def main():
    # 関数定義スペース

    def func():
        ...

    ...    
    # 入力スペース

    # N = splitN(input())
    N, Q = splitA(input())
    A = splitA(input())
    QUERIES = []
    for i in range(Q):
        QUERIES.append(splitA(input()))

    ...

    # 処理スペース
    # a = A.copy()
    # for i in range(N+1):
        # a.append(0)
    
    offset = 0
    segTree = segmentTree(A,0,lambda x,y:x+y)

    for i in QUERIES:
        if i[0] == 1:
            offset+=i[1]
        if i[0] ==2:
            QL,QR =i[1:]
            QL,QR = QL-1,QR-1
            sep_l = (QL + offset)%N
            sep_r = (QR + offset)%N
            if sep_l<=sep_r:
                print(segTree.get_query(sep_l,sep_r+1))
            else:
                rs = 0
                rs+=segTree.get_query(0,sep_r+1)
                rs+=segTree.get_query(sep_l,N)
                print(rs)
    debug("<")

    







    ...



# テストケース中枢処理
def case():
    TESTCASE = 1
    # TESTCASE = int(input()) # テストケース数の指定
    for _ in range(TESTCASE):
        try:
            main()
        except solvedException:
            continue
        # raise unSolvedExeption


# インポート
import sys, itertools, math, heapq
from collections import defaultdict, deque
from sortedcontainers import SortedSet, SortedList, SortedDict  # CPython?

# 定数・環境設定
sys.setrecursionlimit(10**8)
sys.set_int_max_str_digits(0)
dict = defaultdict
UPPER_ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
LOWER_ALPHABET="abcdefghijklmnopqrstuvwxyz"
MOD = 998244353
MAX = 10**18
LRUD = [(0, 1), (0, -1), (1, 0), (-1, 0)]
LURULDRD = [(-1, -1), (-1, 1), (1, -1), (1, 1)]

# 各種関数定義(超圧縮)
## 便利関数
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end); fin()
def prin(stop=False,sep=" ",end="\n",file=sys.stdout):return (lambda*values:printe(*values,sep=sep,end=end)) if stop else (lambda*values:print(*values,sep=sep,end=end,file=file))
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def printYN(f:bool): yes() if f else no()
def fin(f=True): raise solvedException if f else None
## 分割関数
def split(value:str|list,sep:str=" ",func:callable=str) -> list:
    result = []
    if type(value) == list:
        for i in range(len(value)):
            result.append(split(value[i],sep))
        return result
    else:
        if sep in value:
            for i in value.split(sep):
                result.append(func(i))
        else:
            result.append(func(value))
        return result
## 入力受け取り用
def input():return(sys.stdin.readline()).rstrip() #入力定数倍
def splitS(value:str|list,sep:str=" ")->str:return split(value,sep)[0] #文字列・分割して最初
def splitN(value:str|list,sep:str=" ")->int:return split(value,sep,int)[0] # 整数・分割して最初
def splitB(value:str|list,sep:str=" ")->list:return list(split(value,sep)) # 文字列・分割してすべて
def splitA(value:str|list,sep:str=" ")->list:return list(split(value,sep,int)) # 整数・分割してすべて

# 例外クラス
class solvedException(Exception): pass # 処理打ち切り例外
class unSolvedExeption(Exception): # 回答未出力例外
    def __init__(description = "解答が出力されていません。"): super().__init__(description)

# 実行
if __name__ == "__main__":
    case()

# ABC450C
# template

"""
/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 入力
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 *
 * # 具体的なロジック
 *
 *
 *
 *
 *
 * # 出力
 *
 *
 */
"""


def main():
    # 関数定義スペース
    def dfs(pos):
        count = 0
        for offY,offX in LRUD:
            next = pos[0]+offY,pos[1]+offX
            if BOARD[next]=="%":
                return False
            elif BOARD[next] == "#":
                count += 1
                continue
            elif BOARD[next] == ".":
                if next not in done:
                    done.add(next)
                    if dfs(next) == False:
                        BOARD[next] = "%"
                        return False
        return count < 4


    ...    

    # 入力スペース
    """
    入力受け取り例

    S = im.input()
    N = im.intInput()
    H,W = im.listIntInput(2)
    A = im.listIntInput(N)
    """
    def conv(i,j):
        return i*W+j
    BOARD,H,W =Board.Input(lambda x:x)
    BOARD.AddWall("%")
    uf = UnionFind(H*W)
    anticount = dict(lambda:0)
    for i in range(H):
        for j in range(W):
            if BOARD[i,j] == ".":
                for offY,offX in LRUD:
                    next = i+offY,j+offX
                    if BOARD[next] == ".":
                        uf.Unite(conv(i,j),conv(next[0],next[1]))
                    elif BOARD[next] == "%":
                        anticount[i,j]+=1
    result = 0
    for i in range(H):
        for j in range(W):
            uf.UpdateRoot(conv(i,j))
            if BOARD[i,j]==".":
                result += uf.parent[conv(i,j)]==-1
    anti = set()
    for i in anticount:
        uf.UpdateRoot(conv(i[0],i[1]))
        anti.add(uf.parent[conv(i[0],i[1])])
    print(result-len(anti))
    ...

    # 処理スペース

    ...

# テンプレートコピペエリア

class UnionFind:
    """
    Union-Find
    頂点を結合した際に連結する要素の親ノードを1つに統一する
    各頂点の親ノードを高速に返す
    """
    def __init__(self,length:int):
        """
        コンストラクタ

        Args:
            -  n (int):すべて独立したn個ノードとして初期化する
        """
        self.parent=[-1]*length
        self.size = length

    def Unite(self,node_A:int,node_B:int)->None:
        """ノードaとノードbを結合する

        Args:
            -  a (int): 結合したいノード
            -  b (int): 結合したいノード
        """
        node_B,node_A=self.UpdateRoot(node_B),self.UpdateRoot(node_A)
        if node_A==node_B:
            return
        if node_B<node_A:
            self.parent[node_A] += self.parent[node_B]
            self.parent[node_B] = node_A
        else:
            self.parent[node_B] += self.parent[node_A]
            self.parent[node_A] = node_B
    
    def FetchSize(self,node:int)->int:
        """
        ノードの属するグループのサイズを求める
        Args:
        -   ノード番号
        """
        return self.size[self.UpdateRoot(node)]

    def UpdateRoot(self,i:int)->int:
        """親ノードを再帰的に探索する
        途中で見つけた親ノードで各子ノード更新する
        Args:
            -  i (int):探したいノード 
        Returns:
            -  int:親ノード
        """
        if self.parent[i]<0:
            return i
        else:
            self.parent[i]=self.UpdateRoot(self.parent[i])
            return self.parent[i]
class Board():

    """
    二次元ボードを便利に使いやすくするためのクラス
    """ 
    ROTATE_0_DEGREE = 0
    ROTATE_90_DEGREE = 1
    ROTATE_180_DEGREE = 2
    ROTATE_270_DEGREE = 3

    # 自作ボードクラスのショートカット関数
    def Input():
        """
        標準入力からボード作成
        """
        H,W = map(int,input().split())
        return [H,W,Board.InputBoardWithWall(H,W,"#")]


    def InputBoard(height:int,f=lambda:list(input())):
        """
        文字列を吐き出す関数からボード作成
        Args:
            -  height(int):高さ
            -  f(function):入力の形式 指定しなかった場合は自動で
                スペースのない文字列を想定した入力になる
        Returns:
            Board:作成されたボードクラス
        """
        board=[]
        for i in range(height):
            board.append(f())
        return Board(board)

    def InputBoardWithWall(height:int,width:int,wall:any,f:lambda:list(input())):
        """
        文字列を吐き出す関数からボード作成(ATフィールド付)
        Args:
            -  height(int):高さ
            -  width(int):幅
            -  wall:壁に割り当てる値
            -  f(function):入力の形式 指定しなかった場合は自動で
                スペースのない文字列を想定した入力になる
        Returns:
            Board:作成されたボードクラス
        """
        board=[]
        for i in range(height):
            board.append(f()+[wall])
        board.append([wall]*(width+1))
        return Board(board)

    def CreateBoard(height:int,width:int,initial_value):
        """
        指定した高さと幅でボードを作成し、全て初期値を代入する。

        Args:
            -  height (int): 高さ
            -  width (int): 幅
            -  initial_value: 初期値 

        Returns:
            -  Board: 作成されたボード
        """
        raw_board = []
        for i in range(height):
            raw_board.append([initial_value]*width)
        return Board(raw_board)


    def __init__(self,board_data:list):
        """
        インスタンス生成関数
        Args:
            -  board_data(list):生成する元となる二次元配列データ
        """
        self.__data=[]
        self.__height=len(board_data)
        assert 0<self.__height #高さが0以下だった場合はボードの作りようがないためエラー
        self.__width=len(board_data[0])
        for i in range(self.__height):
            assert len(board_data[i])==self.__width #幅がぶれているとこのクラスでは扱えないためエラー
            self.__data.append(board_data[i])
        self.__cells=self.__height*self.__width

    def GetHeight(self):
        """
        ボードの高さの値を返す関数

        Returns:
            -  int:heightの値
        """
        return self.__height

    def get_width(self):
        """
        ボードの幅の値を返す関数

        Returns:
            -  int:widthの値
        """
        return self.__width


    def __len__(self):
        """
        len()を使うための関数
        レコードの数を返す

        Returns:
            -  int:二次元配列のレコードの数
        """
        return self.__cells
    
    
    def __getitem__(self,pos:tuple):
        """
        board[]を利用するための関数
        レコードの値を取り出す

        Args:
            -  (y,x)形式の座標を表すタプル
        Returns:
            -  any:テーブルのy行目j列目の値
        """
        return self.__data[pos[0]][pos[1]]
    
    def Get(self,pos:tuple):
        """
        レコードの値を取り出す関数

        Args:
            -  pos(tuple):(y,x)形式の座標を表すタプル
        Returns:
            -  any:テーブルのy行目j列目の値        
        """        
        return self[pos]

    def __str__(self):
        """
        str()で呼び出される関数
        いい感じに整形して出力する
        Returns:
            -  str:いい感じに整形された二次元配列の文字列
        """
        datas=[]
        sep_count=0
        for i in range(self.__height):
            
            item=" | ".join(str(j) for j in self.__data[i])
            datas.append(item)
            sep_count=max(sep_count,len(item))
            if i==self.__height-1:
                sep="\n"+"-"*sep_count+"-\n"
        return sep.join(datas)

    def Set(self,pos,value):
        """
        値を代入する関数
        Args:
            -  pos(tuple):(y,x)形式の座標を表すタプル
            -  value(any):代入する値
        """
        self[pos]=value

    def __setitem__(self,pos,value):
        """
        board[pos]=valueを使えるようにするための関数
        値を代入する
        Args:
            -  pos(tuple):(y,x)形式の座標を表すタプル
            -  value(any):代入する値
        """
        self.__data[pos[0]][pos[1]]=value

    def IsInsidePositive(self,pos):
        """
        正の整数の範囲内で指定のposがボードの内側に含まれているかどうかを返す関数
        
        Args:
            -  pos (tuple): (y,x)形式の座標を表すタプル
        """
        y,x=pos
        return y<self.__height and x<self.__width

    def IsInsideNegative(self,pos):
        """
        負の整数の範囲内で指定のposがボードの内側に含まれているかどうかを返す関数
        
        Args:
            -  pos (tuple): (y,x)形式の座標を表すタプル
        """
        y,x=pos
        return -1*self.__width<=x and -1*self.__height<=y
    

    def IsInside(self,pos):
        """
        指定のposがボードの内側に含まれているかどうかを返す関数
        ただし、マイナスを許容する
        Args:
            -  pos(tuple):(y,x)形式の座標を表すタプル
        Returns:
            -  bool:含まれているか否か
        """
        return self.IsInsidePositive(pos) or self.IsInsideNegative(pos)

    def Rotate(self,degree:int):
        """
        ボードを回転させる関数
        Args:
            -  degree(int):ROTATE_**_DEGREE
        """
        if degree==self.ROTATE_90_DEGREE:
            self.__data = [list(g) for g in zip(*self.__data[::-1])]
            self.__height,self.__width=self.__width,self.__height
        elif degree==self.ROTATE_180_DEGREE:
            self.__data = [list(g)[::-1] for g in self.__data[::-1]]
        elif degree==self.ROTATE_270_DEGREE:
            self.__data = [list(g) for g in zip(*self.__data)][::-1]
            self.__height,self.__width=self.__width,self.__height

    def __flip_by_vertical(self):
        """
        ボードを縦方向の線対称に反転する
        """
        self.__data = [list(g)[::-1] for g in self.__data]
    
    def __flip_by_holizontal(self):
        """
        ボードを横方向の線対称に反転する
        """
        self.__data = [list(g) for g in self.__data[::-1]]
    
    def Flip(self,vertical=False,horizontal=False):
        """
        ボードを縦か横か指定した方向の線対称に反転する
        Args:
            -  vertical(bool):初期値はFalseで、Trueにすると縦方向に反転する
            -  horizontal(bool):初期値はFalseで、Trueにすると横方向に反転する
        """
        if vertical:
            self.__flip_by_vertical()
        if horizontal:
            self.__flip_by_holizontal()

    def Copy(self):
        """
        コピー関数
        Returns:
            -  Board:別インスタンスで、中身が同じボードクラス
        """
        data=[]
        for i in range(self.__height):
            data.append(self.__data[i].copy())
        return self.__class__(data)

    def Fill(self,value):
        """
        初期化関数
        valueで指定した値でボードのすべてを埋める
        Args:
            -  value(any):埋めたい値
        """
        for i in range(self.__height):
            for j in range(self.__width):
                self.__data[i][j] = value

    def AddWall(self,value):
        """
        ATフィールド関数
        valueで指定した値でボードの右端と下端をひとつ増やす。
        Args:
            -  value(any):増やしたい値
        """
        for i in range(self.__height):
            self.__data[i].append(value)
        self.__width+=1
        self.__height+=1
        self.__data.append([value]*(self.__width))
    
    def Input(f:callable=int)->tuple:
        """二次元ボードの入力

        Args:
            -  f (callable, optional): 各要素にかける関数

        Returns:
            -  tuple: 二次元ボードとHとWの組
        """
        H,W=map(int,input().split())
        board = []
        for i in range(H):
            board.append(list(map(f,list(input()))))
        return Board(board),H,W




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
import sys, itertools, math, heapq,builtins
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

# 各種関数定義
## 便利関数
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end); fin()
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def yesno(f:bool): yes() if f else no()
def fin(f=True): raise solvedException if f else None

## 入力受け取り用
def input():return(sys.stdin.readline()).rstrip() #入力定数倍

"""
入力取得マネージャー
"""
class inputManager:
    __buffer = []
    __index = 0

    @staticmethod
    def input() -> str:
        """
        入力取得関数
        バッファから次の空白･改行文字までの1トークンを取り出す
        バッファが空の場合次の改行文字まで読み出す
        """
        if len(inputManager.__buffer)==0:
            inputManager.__buffer = builtins.input().split()
            inputManager.__index = 0
        result = inputManager.__buffer[inputManager.__index]
        inputManager.__index += 1
        if inputManager.__index==len(inputManager.__buffer):
            inputManager.__buffer = []
        return result
    def intInput() -> int:
        """
        次の数値を取り出す
        数値キャストに失敗すると死ぬ
        """
        return int(inputManager.input())
    def listInput(n:int,f:callable=lambda x:x) -> list:
        """
        n個の入力を配列として返す
        取り出したものを引数に関数fを実行した結果を格納する        

        :param n: 個数
        :type n: int
        :param f: 実行したい関数
        :type f: callable
        """
        result = []
        for i in range(n):
            result.append(f(inputManager.input()))
        return result
    
    def listIntInput(n:int) -> list:
        """
        n個の入力を数値配列として返す
        :param n: 個数
        """ 
        return inputManager.listInput(n,int)

im = inputManager


# 例外クラス
class solvedException(Exception): pass # 処理打ち切り例外
class unSolvedExeption(Exception): # 回答未出力例外
    def __init__(description = "解答が出力されていません。"): super().__init__(description)

# 実行
if __name__ == "__main__":
    case()

# ABC322D


class Board():
    """
    二次元ボードを便利に使いやすくするためのクラス
    """ 
    ROTATE_0_DEGREE = 0
    ROTATE_90_DEGREE = 1
    ROTATE_180_DEGREE = 2
    ROTATE_270_DEGREE = 3

    # 自作ボードクラスのショートカット関数
    def input():
        """
        標準入力からボード作成
        """
        H,W = map(int,input().split())
        return [H,W,Board.input_board_with_wall(H,W,"#")]

    def input_board(height:int,f=lambda:list(input())) -> "Board":
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

    def input_board_with_wall(height:int,width:int,wall:any,f:lambda:list(input())) -> "Board":
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

    def create_board(height:int,width:int,initial_value) -> "Board":
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

    def get_height(self):
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
    
    def get(self,pos:tuple):
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

    def set(self,pos,value):
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

    def is_inside_positive(self,pos):
        """
        正の整数の範囲内で指定のposがボードの内側に含まれているかどうかを返す関数
        
        Args:
            -  pos (tuple): (y,x)形式の座標を表すタプル
        """
        y,x=pos
        return y<self.__height and x<self.__width

    def is_inside_negative(self,pos):
        """
        負の整数の範囲内で指定のposがボードの内側に含まれているかどうかを返す関数
        
        Args:
            -  pos (tuple): (y,x)形式の座標を表すタプル
        """
        y,x=pos
        return -1*self.__width<=x and -1*self.__height<=y
    

    def is_inside(self,pos):
        """
        指定のposがボードの内側に含まれているかどうかを返す関数
        ただし、マイナスを許容する
        Args:
            -  pos(tuple):(y,x)形式の座標を表すタプル
        Returns:
            -  bool:含まれているか否か
        """
        return self.is_inside_positive(pos) or self.is_inside_negative(pos)

    def rotate(self,degree:int):
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
    
    def flip(self,vertical=False,horizontal=False):
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

    def copy(self):
        """
        コピー関数
        Returns:
            -  Board:別インスタンスで、中身が同じボードクラス
        """
        data=[]
        for i in range(self.__height):
            data.append(self.__data[i].copy())
        return self.__class__(data)

    def fill(self,value):
        """
        初期化関数
        valueで指定した値でボードのすべてを埋める
        Args:
            -  value(any):埋めたい値
        """
        for i in range(self.__height):
            for j in range(self.__width):
                self.__data[i][j] = value

    def add_wall(self,value):
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
    
    def input(f:callable=int)->tuple:
        """二次元ボードの入力

        Args:
            -  f (callable, optional): 各要素にかける関数

        Returns:
            -  tuple: 二次元ボードとHとWの組
        """
        H,W=map(int,input().split())
        board = []
        for i in range(H):
            board.append(list(map(f,input().split())))
        return Board(board),H,W

def main():
    # 関数定義スペース

    def findPieces(p):
        result = []
        for i in range(H):
            for j in range(W):
                if p[i,j] == "#":
                    result.append((i,j))
        upperLeft = result[0]
        result[0] = (0,0)
        for i in range(1,len(result)):
            y,x = result[i]
            result[i] = (y-upperLeft[0],x-upperLeft[1])
        return result
        ...
    def placeCandidate(board,mino):
        candidates = []
        for i in range(H):
            for j in range(W):
                for k,l in mino:
                    if board[i+k,j+l]!=-1:
                        break
                else:
                    candidates.append((i,j))
        return candidates

    ...    
    # 入力スペース
    H = 4
    W = 4
    P1_input = Board.input_board(H)
    P2_input = Board.input_board(H)
    P3_input = Board.input_board(H)

    ...


    # 処理スペース
    for P1,P2,P3 in itertools.permutations([P1_input,P2_input,P3_input],3):
        debug("<<")
        debug(P1,P2,P3,sep="\n")
        minoes = []
        for mino in [P1,P2,P3]:
            parts = []
            part = mino
            parts.append(findPieces(part))
            part.rotate(Board.ROTATE_90_DEGREE)
            parts.append(findPieces(part))
            part.rotate(Board.ROTATE_90_DEGREE)
            parts.append(findPieces(part))
            part.rotate(Board.ROTATE_90_DEGREE)
            parts.append(findPieces(part))
            minoes.append(parts)
        piecesCount = 0
        for i in range(3):
            piecesCount+=len(minoes[i][0])
        no(piecesCount!=16)
        for rotateDgreeP1 in range(4):
            grid = Board.create_board(4,4,-1)
            grid.add_wall(-2)
            grid.add_wall(-2)
            grid.add_wall(-2)
            p1Candidates = placeCandidate(grid,minoes[0][rotateDgreeP1])
            for p1i,p1j in p1Candidates:
                for p1y,p1x in minoes[0][rotateDgreeP1]:
                    grid[p1i+p1y,p1j+p1x] = 1
                gridCopy = grid.copy()
                for rotateDegreeP2 in range(4):
                    p2Candidates = placeCandidate(grid,minoes[1][rotateDegreeP2])
                    for p2i,p2j in p2Candidates:
                        for p2y,p2x in minoes[1][rotateDegreeP2]:
                            grid[p2i+p2y,p2j+p2x] = 2
                        for rotateDegreeP3 in range(4):
                            p3Candidates = placeCandidate(grid,minoes[2][rotateDegreeP3])
                            yes(0<len(p3Candidates))
                        grid = gridCopy.copy()
    no()




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
## 便利関数(1行関数)
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end); fin()
def prin(stop=False,sep=" ",end="\n",file=sys.stdout):return (lambda*values:printe(*values,sep=sep,end=end)) if stop else (lambda*values:print(*values,sep=sep,end=end,file=file))
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def printYN(f:bool): yes() if f else no()
def fin(f=True): raise solvedException if f else None
def listbin(num): return split(bin(num)[2:],"",int)

## ワンライン出来なかったもの
def split(value:str,sep:str=" ",func:callable=str) -> list:
    """
    分割関数
    文字列をスペース区切りで分割する。
    """
    result = []
    if sep == "":
        result = list(value)
    else:
        section = 0
        for i in range(len(value)):
            if value[i] == sep:
                result.append(value[section:i])
                section = i
        if i == 0 or section != i:
            result.append(value[section:])
    for i in range(len(result)):
        result[i] = func(result[i])
    return result

## 入力受け取り用
def input():return(sys.stdin.readline()).rstrip() #入力定数倍

# 例外クラス
class solvedException(Exception): pass # 処理打ち切り例外
class unSolvedExeption(Exception): # 回答未出力例外
    def __init__(description = "解答が出力されていません。"): super().__init__(description)

# 実行
if __name__ == "__main__":
    case()

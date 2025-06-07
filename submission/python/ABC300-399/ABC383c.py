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
class Board:
    """
    ボードを使いやすくするクラス
    一次元配列で仮想的に二次元配列を定義する
    初期化時にコンストラクタでサイズHWと初期値を指定し、読み書きが可能

    初期化例 
    Board(H+1,W+1,lambda x:list(input())+["#"] if x<H else ["#"]*(W+1),can_loop=True)
    Board(H+1,W+1,lambda x:list(input()),can_loop=False)

    """
    def __init__(
        self,
        h: int, 
        w: int,
        default: int | str | bool,
        can_loop: bool = True,
    ) -> None:
        """
        初期化関数 インスタンス生成時に呼び出される

        Args:
            h (int): 縦の長さ
            w (int): 横の長さ
            default (int | str | bool): 初期値設定※イミュータブルなものを指定しなければならない
            can_loop (bool, optional): デフォルトでTrue。-1番目を指定したときに一番後ろを見るかどうか
        """
        self.__board = []  # データ
        for i in range(h):
            data = default(i)
            assert len(data) == w, "Illigal input length."
            self.__board += data
        self.__height = h  # 高さ
        self.__weight = w  # 幅
        self.can_loop = can_loop  # ループを許容するか(デフォルトはTrue)

    def __str__(self):
        """
        str()で呼び出されるメソッド
        ただし、二次元配列として中身を確認する場合はself.print()を使うこと

        Returns:
            str: データを文字列にしたもの
        """
        return str(self.__board)

    def __get_board(self):
        """
        一次元配列の中身を二次元配列に変換して返すメソッド
        O(N^2)につき外から利用しない
        self.print()で利用される
        Returns:
            list: 二次元配列に変換したボード
        """
        grid = []
        w = self.get_width()
        h = self.get_height()
        for i in range(0, h):
            grid.append(self.__board[i * w : w * (i + 1)])
        return grid

    def print(self, f=print):  # 出力用
        """出力用メソッド

        Args:
            f (object, optional): 出力時に用いる関数※指定しない場合print関数が呼び出される

        """
        return f(*self.__get_board(), sep="\n")

    def get_height(self) -> int:  # Hの値を取得
        """縦の長さを取得する

        Returns:
            int: 縦の長さ
        """
        return self.__height

    def get_width(self) -> int:  # Wの値を取得
        """横の長さを取得する

        Returns:
            int: 横の長さ
        """
        return self.__weight

    def get_index(self, i: int, j: int) -> int:  # i,jの情報から位置を計算する
        """二次元配列における縦i番目横j番目が一次元配列のどこにあたるかを計算する

        Args:
            i (int): 縦の位置(0-indexed)
            j (int): 横の位置(0-indexed)

        Returns:
            int: 計算結果
        
        例外:
            IndexError: 二次元配列において存在しない場所を指定した場合に呼び出される
        """
        w = self.get_width()
        h = self.get_height()
        if self.can_loop:
            assert -1 * h <= i and i < h, "IndexError: list index out of range"
            assert -1 * w <= j and j < w, "IndexError: list index out of range"
            if i < 0:
                i += h
            if j < 0:
                j += w
        else:
            assert (
                0 <= i and i < h and 0 <= j and j < w
            ), "IndexError: list index out of range"
        return i * w + j  # i*W+jが一次元における指定マスの場所

    def get_pos(self, index: int):
        """一次元配列の場所における二次元配列の位置を計算する。

        Args:
            index (int): 一次元配列の場所(0-indexed)

        Returns:
            i (int): 縦の位置(0-indexed)
            j (int): 横の位置(0-indexed)
        """
        
        i = index // self.get_width()
        j = index % self.get_width()
        return i, j

    def get_value(self, *args) -> int | str | bool:
        """二次元配列における縦i番目横j番目の値を返す

        Args:
            i (int): 縦の位置(0-indexed)
            j (int): 横の位置(0-indexed)

        Returns:
            int | str | bool: 二次元配列の値
        """
        if len(args)==1 and type(args[0])==tuple:
            i,j=args[0]
        elif len(args)==2:
            i,j=args
        assert 1<=len(args) and len(args)<=2, "get_value() takes 1 or 2 positional argument but "+str(len(args))+" were given"
        assert type(i)==int and type(j)==int, "TypeError: list indices must be integers or slices, not"+str(type(i))+","+str(type(j))
        pos = self.get_index(i, j)
        return self.__board[pos]

    def set_value(self, i: int, j: int, value: int | str | bool) -> None:
        """二次元配列における縦i番目横j番目に値を代入する

        Args:
            i (int): 縦の位置(0-indexed)
            j (int): 横の位置(0-indexed)
            value (int | str | bool): 代入する値
        """
        pos = self.get_index(i, j)
        self.__board[pos] = value


# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
H, W, D = map(int,input().split())

BOARD=Board(H+1,W+1,lambda x:list(input())+["#"] if x<H else ["#"]*(W+1),can_loop=True)
# BOARD.print(debug)
# 処理スペース ================================================================================================Lit_to

first_pos=[]
result=set()
for i in range(H):
    for j in range(W):
        if BOARD.get_value(i,j)=="H":
            first_pos.append(((i,j),0))
            result.add((BOARD.get_index(i,j)))

RLUD=[(0,1),(0,-1),(-1,0),(1,0)]

queue=deque(first_pos)
while queue:
    now_pos,count=queue.popleft()
    i,j=now_pos
    if count==D:
        continue
    for diff in RLUD:
        pos=(i+diff[0],j+diff[1])
        index=BOARD.get_index(pos[0],pos[1])
        if BOARD.get_value(pos)=="."and index not in result:
            result.add(index)
            queue.append((pos,count+1))


print(len(result))




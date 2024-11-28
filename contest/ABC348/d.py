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
    # ボードを使いやすくするクラス
    # 初期化時にコンストラクタでサイズHWと初期値を指定する
    # 中身のボードは一次元配列で定義する
    # W個ごとに並べる
    # board.get_height(i,j)で値を取得
    # 範囲外の場合はエラーとして落とす
    # board.set_height(i,j)で値を代入
    # 範囲外の場合はエラーとして落とす
    # board.heightでHの値を返す
    # board.weightでWの値を返す

    def __init__(
        self, h: int, w: int, default: int | str | bool, can_loop: bool = True
    ) -> None:  # 初期化 ※defaultはイミュータブルなものである必要がある
        for i in range(H):#データ
            data=[]
            for j in range(W):
                data.append(default(i))
            self.__board.append(data)
        self.__height = h #高さ
        self.__weight = w #幅
        self.can_loop=can_loop #ループを許容するか(デフォルトはTrue)


    def get_height(self) -> int:  # Hの値を取得
        return self.__height

    def get_width(self) -> int:  # Wの値を取得
        return self.__weight

    def get_index(self, i: int, j: int) -> int:  # i,jの情報から座標を計算する
        if self.can_loop:
            assert (
                -1 * self.get_height() <= i and i < self.get_height()
            ), "IndexError: list index out of range"
            assert (
                -1 * self.get_width() <= j and j < self.get_width()
            ), "IndexError: list index out of range"
            if i < 0:
                i += self.get_height()
            if j < 0:
                j += self.get_width()
        else:
            assert (
                0 <= i and i < self.get_height() and 0 <= j and j < self.get_width()
            ), "IndexError: list index out of range"
        return i * self.get_width() + j  # i*W+jが一次元における指定マスの場所

    def get_pos(self,index:int):
        i=index//self.get_width()
        j=index%self.get_width()
        return i,j

    def get_value(self, i: int, j: int) -> int | str | bool:
        pos = self.get_index(i, j)
        return self.__board[pos]

    def set_value(self, i: int, j: int, value: int | str | bool) -> None:
        pos = self.get_index(i, j)
        self.__board[pos] = value

# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
H, W = map(int,input().split())
BOARD=Board(H+1,W+1,lambda x:list(input())+["#"] if x<H else ["#"]*(W+1),can_loop=True)
N = int(input())
for i in range(N):
    r,c,e=map(int,input().split())
    BOARD.set_value(r-1,c-1,e)
# QUERY=[tuple(map(int,input().split())) for i in range(N)]


# 処理スペース ================================================================================================Lit_to
print(BOARD.__board)

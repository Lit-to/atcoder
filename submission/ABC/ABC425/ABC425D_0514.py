# ABC425D

def main():
    # 関数定義スペース

    ...    

    # 入力スペース
    """
    入力受け取り例

    S = im.input()
    N = im.intInput()
    H,W = im.listIntInput(2)
    A = im.listIntInput(N)
    """

    H,W = im.listIntInput(2)
    BOARD = []
    for i in range(H):
        line = list(im.input()+"@")
        BOARD.append(line)
    BOARD.append(list("@"*(W+1)))
    queue = Queue()
    done = set()
    for i in range(H):
        for j in range(W):
            if (BOARD[i][j]=="#"):
                queue.Enqueue((i,j))
                done.add((i,j))
    while (queue.IsEmpty()==False):
        candidates = []
        while (queue.IsEmpty()==False):
            pos = queue.GetFront()
            queue.Dequeue()
            for i in LRUD:
                aroundPos = pos[0]+i[0],pos[1]+i[1]
                if aroundPos in done:
                    continue
                if BOARD[aroundPos[0]][aroundPos[1]]!=".":
                    continue
                count = 0
                for j in LRUD:
                    aroundAroundPos = aroundPos[0]+j[0],aroundPos[1]+j[1]
                    count+=BOARD[aroundAroundPos[0]][aroundAroundPos[1]]=="#"
                if (count == 1):
                    candidates.append(aroundPos)
                    done.add(aroundPos)
        for i in candidates:
            BOARD[i[0]][i[1]] = "#"
            queue.Enqueue(i)
    result = 0
    for i in range(H):
        for j in range(W):
            result+=BOARD[i][j]=="#"
    print(result)
    ...

    # 処理スペース

    ...

# テンプレートコピペエリア
# 2026-02-25 16:15:43
class Queue:

    def __init__(self):
        """
        コンストラクタ
        空で初期化する
        """
        self.__data = []
        self.__begin = 0
        self.__end = 0

    def __len__(self) -> int:
        """
        キューの長さを返す

        Returns:
            int: self.__dataの長さ
        """
        return self.__end - self.__begin

    def __str__(self) -> str:
        """
        キューの文字列表現を返す

        Returns:
            str: self.__dataの文字列表現
        """
        return str(self.__data[self.__begin:self.__end])
    
    def __getitem__(self, key):
        """
        データのi番目を返す

        Args:
            key (int): インデックス

        Raises:
            IndexError: キューのインデックス番目が存在しない場合

        Returns:
            当該データ型: self.__dataのインデックス番目
        """
        if not self.__begin+key < self.__end:
            raise IndexError
        return self.__data[self.__begin+key]

    def IsEmpty(self) -> bool:
        """
        空かどうかを返す

        Returns:
            bool: self.__dataにデータがあるときのみTrue
        """
        return len(self)==0

    def Enqueue(self,value):
        """
        先頭に値を挿入する

        Args:
            value (any): 挿入する値
        """
        self.__data.append(value)
        self.__end += 1

    def Dequeue(self) -> None:
        """
        先頭の値を削除する

        Raises:
            IndexError: データが存在しない場合
        """
        if self.IsEmpty():
            raise IndexError("list index out of range") 
        self.__begin += 1
    
    def GetFront(self):
        """
        先頭の値を取得する

        Raises:
            IndexError: データが存在しない場合
        Returns:
            当該データ型: 末尾の値
        """
        if self.IsEmpty():
            raise IndexError("list index out of range") 
        return self.__data[self.__begin]

    def Rebuild(self) -> None:
        """
        データを再配置する
        ※すべての値のコピーが発生する
        """
        self.__data = self.__data[self.__begin:self.__end]
        self.__begin = 0
        self.__end = len(self.__data)


# テンプレートコピペここまで
#=====================
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

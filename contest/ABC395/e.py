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


# 関数定義スペース
class priority_queue():
    """
    最小値更新ヒープキュー
    ※import heapq必須
    インスタンス化して使えるようにしたもの。
    """
    def __init__(self,l:list=list()):
        """初期化
        インスタンスを生成した際は順番の変更は行われない。
                
        Args:
            l (list, optional): 初期値配列(ない場合は空の配列が生成される)
        """
        self.data=l.copy()

        if self.data:
            heapq.heapify(self.data)

    def __len__(self):
        """
        要素数を返すメソッド

        Returns:
            int: 要素数
        """
        return len(self.data)

    def __str__(self):#出力用
        """print関数の出力に使うための文字列化

        Returns:
            str: self.dataを文字列としたもの

        """
        return str(self.data)

    def enq(self,value:int):#入れる
        """データを挿入し、ヒープ化する。

        Args:
            value (int): 挿入する値
        """
        heapq.heappush(self.data,value)

    def add(self,value:int):#入れる
        """データを挿入し、ヒープ化する。

        Args:
            value (int): 挿入する値
        """
        self.enq(value)


    def deq(self):#出す
        """要素のうち最小値を取り出す。

        Returns:
            int: 取り出した値
        """
        return heapq.heappop(self.data)

    def top(self):
        """要素のうち最小値の値を返す。

        Returns:
            int: 最小値
        """
        return self.data[0]


    def empty(self):
        """要素が空かどうかを返す。

        Returns:
            bool: 空だった場合True,そうじゃない場合False
        """
        return not bool(self.data)



def main():
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    N, M, X = map(int,input().split())
    GRAPH=dict(lambda:[])
    for i in range(M):
        u,v=map(int,input().split())
        GRAPH[u].append((1,v))
        GRAPH[v].append((X+1,u))
    # 処理スペース ================================================================================================Lit_to

    queue=priority_queue()
    done=set()
    queue.add((0,1))
    # done.add(1)
    while not queue.empty():
        cost,to=queue.deq()
        done.add(to)
        if to == N:
            printe(cost)
        else:
            for i in GRAPH[to]:
                if i[1] not in done:
                    queue.add((i[0]+cost,i[1]))
                    # done.add(i[1])
    


if __name__=="__main__":
    main()

# Python用ディレクトリ
[全体ディレクトリ](https://github.com/Lit-to/atcoder)

Pythonディレクトリへようこそ。

-   python/template内は1コンテストのテンプレートセット
-   python/material内はコピペ素材

を置きました。


# テンプレートの中身とその説明
```py
# インポート(本編はだいたい30行目あたり)
import sys,itertools,math,heapq,pypyjit
from collections import defaultdict,deque
from sortedcontainers import SortedSet, SortedList, SortedDict
pypyjit.set_param('max_unroll_recursion=-1')
sys.setrecursionlimit(10**8)
sys.set_int_max_str_digits(0)
dict=defaultdict
```
pypy3.10で動かすことを想定している。Cpythonでは動かない
インポートとおまじないセット。  
インポート部分:よく使う便利なライブラリは使用の有無に関係なくインポートしており、ここで150ms程度の処理時間がある。(``sortedcontainers``が1/3くらいの時間を占めてたはず)
おまじないセット部分:各種アルゴリズムの高速化をするためのおまじない。詳しくは調べてくれ。    
最後の行はdictの上書き。dictがdefaultdictになって困ることはないのでこのようにしている。  

```py
# 便利定数定義
ALPHABET="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# ALPHABET="abcdefghijklmnopqrstuvwxyz"
MOD=998244353
MAX=10**18
```
あると便利な定数を宣言している。  
ALPHABETは重宝しているがそれ以外は忘れて直で書いていることもしばしば。  

```py
# 便利関数定義
def input(): return (sys.stdin.readline()).rstrip()
def yes(): print("Yes"); exit()
def no(): print("No"); exit()
def printe(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end); exit() #Cpythonでは動かない
def listr(l:list): return "".join(l)
def debug(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def look(pos:tuple,board:list): return board[pos[0]][pos[1]] #HWボードの(i,j)の値を参照して返す関数
def printYN(f:bool): yes() if f else no()
# 関数定義スペース


```
あると便利な関数を宣言している。
-   inputの上書きは定数倍高速化の一種。標準入力の読み取りが多少高速になる。
-   yes/no yes/endと出力したのち**プログラムを終了する**。地味に便利。
-   printe(str) 引数はprint関数とまったく同じ。文字列を出力したのち**プログラムを終了する。** print and endの略としているが、ぷりんて と読むことがほとんど。
-   listr(list) 引数の配列をすべて結合した文字列を返す。登場することは多くない。
-   debug(str) 引数はprint関数とまったく同じ。文字列を**標準エラー出力として**出力する。VSコード上では標準出力との見分けがつかないが、このまま提出しても標準出力のみチェックされるためデバッグに便利。
-   printYN(bool) True/Falseをyes/noに対応させて出力し、**プログラムを終了する**。しょうもない条件分岐や、三項演算子を書く必要がなくなる。
-   look(pos:tuple,board:list) (i,j)というデータを渡すとボードの特定の位置を返す。

その他、各問題で関数を宣言する場合はこれらの下の関数定義スペースで宣言・定義する。
```py
# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
N = int(input())
H, W = map(int,input().split())
A = list(map(int,input().split()))
S = input()
# S = list(input())
# S = list(input().split())
# BOARD = [list(input()) for i in range(H)]#文字列のリスト
# BOARD = [list(map(int,input().split())) for i in range(H)]#数値のリスト
# A = list(map(lambda x:int(x)-1,input().split())) # 0-indexedで値を取得
# A = map(lambda x:x,sorted(list(map(int,(input().split())))))#数の組み合わせを並び替えて渡す
# debug("======output is start======")
```
標準入力を受け取るスペース。ここで宣言した変数はすべて大文字にし、書き換えはこの場限りとする。
```py
# 処理スペース ================================================================================================Lit_to
```
実際の処理を書くスペース。ここで宣言した変数はすべて小文字にする。





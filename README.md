# AtCoder精進用レポジトリ

このレポジトリはりっとーがAtCoderを精進したり、土曜日に解いたりするときに使うレポジトリです。
主にpythonディレクトリ内を使っていますが言語が増えたら言語ディレクトリが増えてもいいと思っています。
[Pythonに関する詳細](https://github.com/Lit-to/atcoder/blob/main/python/README.md)

# 変数の命名ルール

## 各言語共通
変数の命名方式は以下上から優先順位が高いものとする。

-   入力を受け取る時の変数の名前は入力形式のアルファベットをそのまま採用し、必ず大文字にする。
    -   同じ変数で被ってしまっている場合はアルファベット順に次のものを採用し、被らないようにする。
    -   アルファベット順からあぶれてしまうときは大文字で別の名前を付ける。
    -   入力がN行の場合や、横並びでN個の場合はlist型にまとめる。
    -   入力がテストケース関係なく同じ個数の組になっているものはtuple型にする。
    -   入力を受け取る変数は入力を受け取った後データの変化が起きないようにする。
-   定数は大文字で命名する。
    -   命名は意味が分かるような英単語を採用し、1文字での命名はしない。
        -   問題に悩んでいてすぐに提出するような状況ではない場合は変数宣言の際にコメントを付す。
    -   定数は入力を受け取るときと同時に宣言する。
    -   定数は宣言以降の処理過程でデータの変化が起きないようにする。
-   データの処理・出力時に必要な変数はすべて小文字とする。
    -   for文、while文の繰り返し変数は``i,j...``とする。
    -   二次元平面、三次元立方の座標を表す変数は``x,y,z``とする。
    -   その他の命名は定数に準ずる。
    -   

## devディレクトリ
-   作業途中のファイルを格納する場所

## contestディレクトリ

コンテスト提出のためのプログラムと記録が入っている。  
コミットは以下のタイミングで行う。
-   コンテスト開始前にディレクトリをコピーしたとき
-   コンテスト終了直後
-   終了後の延長戦終了後
-   その他必要そうなとき(あいまい)

## templateディレクトリ

python/template内は1コンテストのテンプレートセット  
a~gまでのpyファイルと、記録ファイル(report.md)がある。  
このディレクトリを丸ごとコピーして1コンテストで使用する。  

a~g.pyはmaterial/template.pyと同様で、その中身は以下になっている。

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
def yes(f=None): print("Yes") if (f==None or f) else None; exit() if f!=None else None
def no(f=None): print("No") if (f==None or f) else None;exit() if f!=None else None
def printe(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end); exit() #Cpythonでは動かない
def listr(l:list): return "".join(l)
def debug(*values: object,sep: str | None = " ",end: str | None = "\n",): print(*values,sep=sep,end=end,file=sys.stderr) #デバッグ出力用
def look(pos:tuple,board:list): return board[pos[0]][pos[1]] #HWボードの(i,j)の値を参照して返す関数
def printYN(f:bool): yes() if f else no()
# 関数定義スペース


```
あると便利な関数を宣言している。
-   inputの上書きは定数倍高速化の一種。標準入力の読み取りが多少高速になる。
-   yes/no yes/endと出力したのち**プログラムを終了する**。地味に便利。引数にラムダ式を入れることで評価してTrueの時のみ動作させることも出来る。
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


## pypyjit.py
pypyjitはpypyでないとインポートできないためいちいち提出時にコメントを解除する手間を省くためこの場所に配置


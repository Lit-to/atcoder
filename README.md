# AtCoder精進用レポジトリ

このレポジトリはりっとーがAtCoderを精進したり、土曜日に解いたりするときに使うレポジトリです。
主にpythonディレクトリ内を使っていますが言語が増えたら言語ディレクトリが増えてもいいと思っています。
[Pythonに関する詳細](https://github.com/Lit-to/atcoder/blob/main/python/README.md)

# 変数の命名ルール

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

# レポジトリ構成
## devディレクトリ
-   作業途中のファイルを格納する場所

## submissionディレクトリ

コンテスト提出のためのプログラムと記録が入っている。  
コミットは以下のタイミングで行う。
-   コンテスト開始前にディレクトリをコピーしたとき
-   コンテスト終了直後
-   終了後の延長戦終了後
-   その他必要そうなとき(あいまい)

## TEMPLATEディレクトリ

a~gまでのpyファイルと、記録ファイル(``report.md``)がある。  
このディレクトリを丸ごとコピーして1コンテストで使用する。  

a~g.pyは``material/template.py``と同様で、その中身は以下になっている。

### main関数

```py
def main():
    # 関数定義スペース
    def func():
        ...
    ...    

    # 入力スペース
    N = int(input())
    H, W = map(int,input().split())
    A = list(map(int,input().split()))
    S = input()
    S = list(input())
    ...

    # 処理スペース
    ...
```

-   その問題のメインロジック部分。  
-   本来、どの言語もimport等の外部モジュールの呼び出しが先にくるが、競プロ用と割り切っているため**提出のコアになるところ**を上部に持ってきている。  
-   問題で必要な関数はmain関数内に書く。
-   各問題に合わせ、入力をもらう場所は各関数で利用できるようにするためにmain直下に記述する。
    -   標準入力を受け取るスペースで宣言した変数はすべて大文字にし、書き換えはこの場限りとする。
-   そのほか、問題の解答処理を書く。

### case関数

```py
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

```

-   マルチテストケースを回すための部分。``TESTCASE``回``main()``を実行する。
-   マルチケースの場合はテストケース数を指定できるようにする。
    -   ``unSolvedException``を発生させれば、``solvedException``を通らないとエラーを起こす。
        -   提出前に出力忘れに気づくためのエラー挿入用でつけた。
        -   (ただし、ここは考え中。邪魔に感じるかも...)


### インポート

```py

# インポート
import sys, itertools, math, heapq
from collections import defaultdict, deque
from sortedcontainers import SortedSet, SortedList, SortedDict  # CPython?

```

-   各種モジュールのインポート部分。
-   pypy3.10で動かすことを想定している。(``sortedcontainers``が現時点でのCPythonには存在しない)
-   よく使う便利なライブラリは使用の有無に関係なくインポートしており、ここで150ms程度の処理時間がある。(``sortedcontainers``が1/3くらいの時間を占めてたはず)

### 定数・環境設定

```py

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

```

-   あると便利な定数を宣言している。  
-   ``LRUD``と``LURULDRD``は四方・八方のどちらにするかによって変わるため、斜めのみ独立している。八方の場合は結合して利用する。
-   コンテスト中は``dict``を``defaultdict``として取り扱っている。


### 便利関数定義


```py

# 便利関数定義(超圧縮)
def input(): return (sys.stdin.readline()).rstrip()
def printe(*values,sep=" ",end="\n"):print(*values,sep=sep,end=end); fin()
def yes(f=True): printe("Yes") if (f) else None
def no(f=True): printe("No") if (f) else None
def debug(*values,sep=" ",end="\n"): print(*values,sep=sep,end=end,file=sys.stderr)
def printYN(f:bool): yes() if f else no()
def fin(f=True): raise solvedException if f else None


```
あると便利な関数を宣言している。
-   ``input``:inputの上書き。定数倍高速化の一種で、標準入力の読み取りが多少高速になる。
-   ``printe(str)``:引数はprint関数とまったく同じ。文字列を出力したのち**そのテストケースを終了する** print and endの略としているが、ぷりんて と読むことがほとんど。
-   ``yes()``/``no()``:``yes``/``no``と出力したのち**そのテストケースを終了する**。地味に便利。引数に条件式を入れ、Trueの時のみ動作させることも出来る。
-   ``debug(str)``:引数はprint関数とまったく同じ。文字列を**標準エラー出力として**出力する。VSコード上では標準出力との見分けがつかないが、このまま提出しても標準出力のみチェックされるためデバッグに便利。
-   ``printYN(bool)``:``True``/``False``をyes/noに対応させて出力し、**そのテストケースを終了する**。しょうもない条件分岐や、三項演算子を書く必要がなくなる。
-   ``fin(bool)``:プログラムをその場で終了する。引数に条件式を入れ、Trueの時のみ動作させることも出来る。**※出力を伴わないため、利用には要注意**

## materialディレクトリ
-   コンテストで使ったら便利そうなスニペット群を置いている。


## pypyjit.py
pypyjitはpypyでないとインポートできないためいちいち提出時にコメントを解除する手間を省くためこの場所に配置


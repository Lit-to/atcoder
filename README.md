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


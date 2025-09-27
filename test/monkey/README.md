# テスター

##  使い方

1.  ``config.txt``に以下のように記述
```sh
python r.py input.txt TEST 10
python sampleA.py
python sampleB.py
```

-   1行目:テストケース生成スクリプトの実行コマンド
-   2行目:計測プログラムA
-   3行目:計測プログラムB

2.  ``test.sh``を実行！

```
======== Summary ========
Total testcases: 10
NG (difference) : 0
Avg Time (A)    : 16 ms
Avg Time (B)    : 16 ms
TLE:2000+ms (A) : 0
TLE:2000+ms (B) : 0
======== Summary ========
Saved OUTPUT/result_20250927_043135.log.
```

こういうのが出ればOK

# テストケース生成スクリプト

テストケース生成スクリプトも記述した。

-   是非はありそう。

## 使い方

-   ``input.txt``にこう書く

```
N M
... A_N
A_M
```
-   N→ランダムな整数
-   M→ランダムな整数
-   ...→配列であることを表す。後ろに書いたものの添え字の長さ
-   A_M→整数をM行

みたいな。



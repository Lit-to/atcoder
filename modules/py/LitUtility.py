import math


class LitUtility:
    def Search(ok:int,ng:int,f:bool)->int:
        """二分探索を行う関数
        単調増加の範囲においてokのうちいちばんngに近いものの値を返す
        利用例:
        -  lambda i:a[i]<x xを含まない最大のiを返す
        -  lambda i:a[i]<=x xを含む最大のiを返す

        Args:
            -  ok (int): 評価関数fに渡したときに必ずTrueを返すことが保証されている値
            -  ng (int): 評価関数fに渡したときに必ずFalseを返すことが保証されている値
            -  f (bool): 評価関数(引数1/戻り値bool)

        Returns:
            -  int: 結果
        """
        while 1<abs(ok-ng):
            mid=(ng+ok)//2
            if f(mid):
                ok=mid
            else:
                ng=mid
        return ok

    def Compression(A: list) -> list:
        """座標圧縮
        座標を左上に詰める。
        Aをコピー、重複を消し、ソートする。

        Args:
            -  A (list): 圧縮する配列が入ったリスト

        Returns:
            -  list: 圧縮結果
        """
        B = sorted(list(set(A.copy())))
        result = []  # 結果となるべき配列
        for i in A:
            result.append(LitUtility.Index(B, i))  # Aの要素がBのうち何番目にあたるかを返す
        return result


    def Index(a: list, i: int) -> int:  # 簡易二分探索
        # 二分探索で配列の中のiが何番目にあるかを返す
        # →二分探索モジュールと同様のためドキュメント不在
        f = lambda x: a[x] <= i
        ok = -1
        ng = len(a)
        while 1 < abs(ok - ng):
            mid = (ng + ok) // 2
            if f(mid):
                ok = mid
            else:
                ng = mid
        else:
            return ok
    def Factorial(n: int) -> int:
        """
        n!の結果を返す。

        より具体的には整数nの階乗の値を返す。

        Args:
            -  n(int):nの値

        Returns:
            -  int: 計算結果
        """
        return LitUtility.Permutation(n, n)

    def Permutation(n: int, k: int) -> int:
        """
        nPkの値を返す。
        より具体的にはn個の整数からk個を順番に並べられる通り数を返す。

        Args:
            -  n(int):nの値
            -  k(int):kの値

        Returns:
            -  int: 計算結果
        """
        result = 1
        for i in range(n, n - k, -1):
            result *= i
        return result

    def Combination(n: int, k: int) -> int:
        """
        nCkの値を返す。
        より具体的にはn個の整数からk個を選ぶ組み合わせ数を返す。

        Args:
            -  n(int):nの値
            -  k(int):kの値

        Returns:
            -  int: 計算結果
        """
        return LitUtility.Permutation(n, k) // LitUtility.Factorial(k)

    def CalcGCD(value_a: int, value_b: int) -> int:
        """互除法で最大公約数を求める関数

        Args:
            -  value_a (int): 求めたい値A
            -  value_b (int): 求めたい値B

        Returns:
            -  int: AとBの最大公約数
        """
        if value_a < value_b:
            value_a, value_b, value_b, value_a
        while value_b != 0:
            temp = value_b
            value_b = value_a % value_b
            value_a = temp
        return value_a

    def Prime(num:int) -> list:
        """素因数分解の結果を返す
        ※利用するためには import mathが必須

        Args:
            -  num (int): 合成数または素数

        Returns:
            -  list: 分解した素数を返す
        """
        result=[]
        while num%2==0:
            num//=2
            result.append(2)
        c=3
        while c<=math.sqrt(num):
            if num%c==0:
                num//=c
                result.append(c)
            else:
                c+=2
        if num!=1:
            result.append(num)
        return result



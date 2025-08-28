import math
class lit_math:
    def factorial(n: int) -> int:
        """
        n!の結果を返す。

        より具体的には整数nの階乗の値を返す。

        Args:
            n(int):nの値

        Returns:
            int: 計算結果
        """
        return lit_math.permutation(n, n)

    def permutation(n: int, k: int) -> int:
        """
        nPkの値を返す。
        より具体的にはn個の整数からk個を順番に並べられる通り数を返す。

        Args:
            n(int):nの値
            k(int):kの値

        Returns:
            int: 計算結果
        """
        result = 1
        for i in range(n, n - k, -1):
            result *= i
        return result

    def combination(n: int, k: int) -> int:
        """
        nCkの値を返す。
        より具体的にはn個の整数からk個を選ぶ組み合わせ数を返す。

        Args:
            n(int):nの値
            k(int):kの値

        Returns:
            int: 計算結果
        """
        return lit_math.permutation(n, k) // lit_math.factorial(k)

    def gcd(value_a: int, value_b: int) -> int:
        """互除法で最大公約数を求める関数

        Args:
            value_a (int): 求めたい値A
            value_b (int): 求めたい値B

        Returns:
            int: AとBの最大公約数
        """
        if value_a < value_b:
            value_a, value_b, value_b, value_a
        while value_b != 0:
            temp = value_b
            value_b = value_a % value_b
            value_a = temp
        return value_a

    def prime(num:int) -> list:
        """素因数分解の結果を返す
        ※利用するためには import mathが必須

        Args:
            num (int): 合成数または素数

        Returns:
            list: 分解した素数を返す
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



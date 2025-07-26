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


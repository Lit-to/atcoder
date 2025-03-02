class factrial:
    """
    階乗を計算するクラス
    必要分の階乗を計算し、記録しておく。
    二度目に呼び出されたときは計算せず記録した値を返す。
    """
    def __init__(self):
        """
        インスタンス作成
        """
        self.table = dict()
        self.key = 1
        self.table[1] = 1

    def calc(self, n: int)-> int:
        """
        n!の結果を返す

        Args:
            n (int): 求めたい値

        Returns:
            int: n!の値
        """
        result = self.table[self.key]
        while self.key < n:
            self.key += 1
            result *= self.key
            self.table[self.key] = result
        return result

    def __check(self, n: int) -> bool:
        """
        値を既に記録済みかどうかを返す。

        Args:
            n (int): 調べたい値

        Returns:
            bool: 記録済みならTrue
        """
        return n < self.key

    def __len__(self) -> int:
        """
        記録済みの値の数を返す。

        Returns:
            int: 値
        """
        return len(self.table)

    def factrial(self, n: int) -> int:
        """
        n!の演算をする。

        Args:
            n (int): 求めたい値

        Raises:
            ValueError: nが0未満だとエラー

        Returns:
            int: n!の値
        """
        if n < 0:
            raise ValueError
        elif n <= 1:
            return 1
        elif self.__check(n):
            return self.table[n]
        else:
            return self.calc(n)

    def f(self, n: int):
        """
        n!の演算をする。

        Args:
            n (int): 求めたい値

        Raises:
            ValueError: nが0未満だとエラー

        Returns:
            int: n!の値        """
        return self.factrial(n)


if __name__ == "__main__":
    fact = factrial()
    print(fact.f(40))
    print(fact.f(11))

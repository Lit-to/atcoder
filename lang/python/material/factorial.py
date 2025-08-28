class factorial:
    """階乗を計算するクラス
    過去に計算済みの階乗を記録し、もういちど登場した時は再計算しない。
    """

    def __init__(self):
        """
        コンストラクタ

        key:int 最後に計算した階乗の添え字
        table:dict key番目までの階乗情報
        """
        self.key = 1
        self.table = dict()
        self.table[1] = 1

    def calc(self, n: int) -> int:
        """n*(n-1)!の値を返す

        引数:
            n (int): n

        戻り値:
            int: n!の値
        """
        result = self.table[self.key]
        while self.key < n:
            self.key += 1
            result *= self.key
            self.table[self.key] = result
        return result

    def isExist(self, n: int) -> bool:
        """n!の値を計算済みかどうかを返す

        引数:
            n (int): n

        戻り値:
            bool: 存在するかどうか
        """
        return n < self.key

    def __len__(self) -> int:
        """テーブルの長さを返す
        Returns:
            int: テーブルの長さ
        """
        return len(self.table)

    def factorial(self, n: int) -> int:
        """n!の値を求める

        引数:
            n (int): n

        エラー:
            ValueError: 0以下の値を与えた場合に発出するエラー

        戻り値:
            int: n!の値
        """
        if n < 0:
            raise ValueError
        elif n == 1:
            return 1
        elif self.isExist(n):
            return self.table[n]
        else:
            return self.calc(n)

    def f(self, n: int) -> int:
        """
        factrial()のショートカット関数
        """
        return self.factorial(n)

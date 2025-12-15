class prefix_sum():
    """
    累積和クラス
    """
    def __init__(self, value: list, reverse: bool = False):
        """
        コンストラクタ
        累積和の事前計算を行う

        Args:
            -  value (list): 求めたい値配列
            -  reverse (bool, optional): 反転するかどうか
        """
        self.__data=[0]
        for i in value:
            self.__data.append(self.__data[-1] + i)
        self.__data.reverse if reverse else None
        self.__data = tuple(self.__data)
    def get_sum(self, left: int, right: int):
        """半開区間[l,r)の総和を取得する。

        Args:
            -  left (int): 左端
            -  right (int): 右端

        Returns:
            -  int: 総和の結果
        """
        return self.__data[right] - self.__data[left]

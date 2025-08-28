class FenewicTree:
    """
    フェニック木(BIT-Tree)を作成する
    渡された配列のうち0番目からi番目までの区間総和をO(logN)で計算する。
    渡された配列のうちi番目の値にxを足す行為をO(logN)で計算する。
    """

    def __init__(self, arg: int | list | tuple):
        """
        コンストラクタ
        フェニック木を構成する配列を初期化する。
        初期化時はintか、listかtupleを指定できる。
        intを渡した場合は0で全て初期化する。

        Args:
            arg (list | tuple): フェニック木を構成する配列
            arg (int): すべてを0で初期化する場合の0の個数

        """
        if type(arg) == int:
            self.__data = [0] * (arg + 1)
            self.__length = arg + 1
        elif type(arg) == list or type(arg) == tuple:
            self.__length = len(arg) + 1
            self.__data = [0] * self.__length
            for i in range(self.__length - 1):
                self.add(i + 1, arg[i])

    def __len__(self) -> int:
        """
        木の長さを返す

        Returns:
            int: 木の長さ
        """
        return self.__length

    def add(self, index: int, x: int) -> None:
        """木のindex番目にxを足す。

        Args:
            index (int):足したいindex
            x (int): 足す値x
        """
        while index < len(self.__data):
            self.__data[index] += x
            binary = index
            num = 1
            while True:
                if binary % 2 == 1:
                    break
                else:
                    binary >>= 1
                    num *= 2
            index += num

    def sum(self, index: int) -> int:
        """index番目までの総和を返す。

        Args:
            index (int): 求めたい添え字

        Returns:
            int: 計算結果
        """
        if index == 0:
            return 0
        result = 0
        while 0 < index:
            result += self.__data[index]
            binary = index
            num = 1
            while True:
                if binary % 2 == 1:
                    break
                else:
                    binary >>= 1
                    num *= 2
                    continue
            index -= num
        return result

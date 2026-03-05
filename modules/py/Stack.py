# 2026-02-25 16:15:43
class Stack:
    def __init__(self):
        """
        コンストラクタ
        空で初期化する
        """
        self.__data = []
        self.__begin = 0
        self.__end = 0

    def __len__(self)->int:
        """
        配列の長さを返す

        Returns:
            int: self.__dataの長さ
        """
        return self.__end - self.__begin

    def __str__(self)->str:
        """
        スタックの文字列表現を返す

        Returns:
            str: self.__dataの文字列表現
        """
        return str(self.__data[self.__begin:self.__end])

    def __getitem__(self, key:int):
        """
        データのi番目を返す

        Args:
            key (int): インデックス

        Raises:
            IndexError: スタックのインデックス番目が存在しない場合

        Returns:
            当該データ型: self.__dataのインデックス番目
        """
        if not self.__begin+key < self.__end:
            raise IndexError
        return self.__data[self.__begin+key]

    def IsEmpty(self)->bool:
        """
        空かどうかを返す

        Returns:
            bool: self.__dataにデータがあるときのみTrue
        """
        return len(self) == 0

    def Push(self,value)->None:
        """
        末尾に値を挿入する

        Args:
            value (any): 挿入する値
        """
        if len(self.__data) <= self.__end:
            self.__data.append(-1)
        self.__data[self.__end] = value
        self.__end += 1

    def Pop(self):
        """
        末尾の値を削除する

        Raises:
            IndexError: データが存在しない場合
        """
        if self.IsEmpty():
            raise IndexError("list index out of range")
        self.__end -= 1
    
    def GetBack(self):
        """
        末尾の値を取得する

        Raises:
            IndexError: データが存在しない場合
        Returns:
            当該データ型: 末尾の値
        """
        if self.IsEmpty():
            raise IndexError("list index out of range")
        return self.__data[self.__end - 1]

    def Rebuild(self) -> None:
        """
        データを再配置する
        ※すべての値のコピーが発生する
        """
        self.__data = self.__data[self.__begin:self.__end]
        self.__begin = 0
        self.__end = len(self.__data)
# 2026-02-25 17:05:10
class Queue:

    def __init__(self):
        """
        コンストラクタ
        空で初期化する
        """
        self.__data = []
        self.__begin = 0
        self.__end = 0

    def __len__(self) -> int:
        """
        キューの長さを返す

        Returns:
            int: self.__dataの長さ
        """
        return self.__end - self.__begin

    def __str__(self) -> str:
        """
        キューの文字列表現を返す

        Returns:
            str: self.__dataの文字列表現
        """
        return str(self.__data[self.__begin:self.__end])
    
    def __getitem__(self, key):
        """
        データのi番目を返す

        Args:
            key (int): インデックス

        Raises:
            IndexError: キューのインデックス番目が存在しない場合

        Returns:
            当該データ型: self.__dataのインデックス番目
        """
        if not self.__begin+key < self.__end:
            raise IndexError
        return self.__data[self.__begin+key]

    def IsEmpty(self) -> bool:
        """
        空かどうかを返す

        Returns:
            bool: self.__dataにデータがあるときのみTrue
        """
        return len(self)==0

    def Enqueue(self,value):
        """
        先頭に値を挿入する

        Args:
            value (any): 挿入する値
        """
        self.__data.append(value)
        self.__end += 1

    def Dequeue(self) -> None:
        """
        先頭の値を削除する

        Raises:
            IndexError: データが存在しない場合
        """
        if self.IsEmpty():
            raise IndexError("list index out of range") 
        self.__begin += 1
    
    def GetFront(self):
        """
        先頭の値を取得する

        Raises:
            IndexError: データが存在しない場合
        Returns:
            当該データ型: 末尾の値
        """
        if self.IsEmpty():
            raise IndexError("list index out of range") 
        return self.__data[self.__begin]

    def Rebuild(self) -> None:
        """
        データを再配置する
        ※すべての値のコピーが発生する
        """
        self.__data = self.__data[self.__begin:self.__end]
        self.__begin = 0
        self.__end = len(self.__data)


from collections import deque
import random

litQ = Queue()
stlQ = deque()
testCount = 5
testList = [0]*(testCount+1)
for i in range(2*10**5):
    query = random.randint(0,testCount)
    testList[query] += 1
    if query==0:
        r = random.randint(0,10**9)
        litQ.Enqueue(r)
        stlQ.append(r)
    elif query==1:
        assert len(litQ)==len(stlQ)
        if len(stlQ)!=0:
            litQ.Dequeue()
            stlQ.popleft()
    elif query==2:
        assert len(litQ)==len(stlQ)
        if len(stlQ)!=0:
            r = random.randint(0,len(stlQ)-1)
            assert litQ[r]==stlQ[r]
    elif query==3:
        assert litQ.IsEmpty() == (len(stlQ) == 0)
    elif query==4:
        assert len(litQ)==len(stlQ)
        if len(stlQ)!=0:
            assert litQ.GetFront() == stlQ[0]
    else:
        litQ.Rebuild()
    assert str(litQ).strip() == str(stlQ).strip()[6:-1]
print("OK")
print("Log:",testList)




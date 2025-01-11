import heapq
class priority_queue():
    """
    最小値更新ヒープキュー
    ※import heapq必須
    インスタンス化して使えるようにしたもの。
    """
    def __init__(self,l:list=list()):
        """初期化
        インスタンスを生成した際は順番の変更は行われない。
                
        Args:
            l (list, optional): 初期値配列(ない場合は空の配列が生成される)
        """
        self.data=l.copy()

        if self.data:
            heapq.heapify(self.data)

    def __len__(self):
        """
        要素数を返すメソッド

        Returns:
            int: 要素数
        """
        return len(self.data)

    def __str__(self):#出力用
        """print関数の出力に使うための文字列化

        Returns:
            str: self.dataを文字列としたもの

        """
        return str(self.data)

    def enq(self,value:int):#入れる
        """データを挿入し、ヒープ化する。

        Args:
            value (int): 挿入する値
        """
        heapq.heappush(self.data,value)

    def add(self,value:int):#入れる
        """データを挿入し、ヒープ化する。

        Args:
            value (int): 挿入する値
        """
        self.enq(value)


    def deq(self):#出す
        """要素のうち最小値を取り出す。

        Returns:
            int: 取り出した値
        """
        return heapq.heappop(self.data)

    def top(self):
        """要素のうち最小値の値を返す。

        Returns:
            int: 最小値
        """
        return self.data[0]


    def empty(self):
        """要素が空かどうかを返す。

        Returns:
            bool: 空だった場合True,そうじゃない場合False
        """
        return not bool(self.data)
class reversed_priority_queue():
    """
    最大値更新ヒープキュー
    最小値更新ヒープキューに-1倍しただけ
    ※ priority_queue必須
    """
    def __init__(self,l:list=list()):
        """初期化
        インスタンスを生成した際は順番の変更は行われない。
                
        Args:
            l (list, optional): 初期値配列(ない場合は空の配列が生成される)
        """
        self.data=priority_queue([i*-1 for i in l])

    def __len__(self):
        """
        要素数を返すメソッド

        Returns:
            int: 要素数
        """
        return len(self.data)

    def __str__(self):#出力用
        """print関数の出力に使うための文字列化

        Returns:
            str: self.dataを文字列としたもの

        """
        return str(list(map(lambda x:int(x)*-1,str(self.data)[1:-1].split(","))))
        # return str(self.data)

    def enq(self,value:int):#入れる
        """データを挿入し、ヒープ化する。

        Args:
            value (int): 挿入する値
        """
        self.data.enq(value*-1)

    def add(self,value:int):#入れる
        """データを挿入し、ヒープ化する。

        Args:
            value (int): 挿入する値
        """
        self.enq(value*-1)


    def deq(self):#出す
        """要素のうち最大値を取り出す。

        Returns:
            int: 取り出した値
        """
        return self.data.deq()*-1

    def top(self):
        """要素のうち最大値の値を返す。

        Returns:
            int: 最大値
        """
        return self.data.top()*-1


    def empty(self):
        """要素が空かどうかを返す。

        Returns:
            bool: 空だった場合True,そうじゃない場合False
        """
        return self.data.empty()




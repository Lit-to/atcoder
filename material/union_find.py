class unionFind:
    """
    Union-Find
    頂点を結合した際に連結する要素の親ノードを1つに統一する
    各頂点の親ノードを高速に返す
    """
    def __init__(self,n:int):
        """
        コンストラクタ

        Args:
            -  n (int):すべて独立したn個ノードとして初期化する
        """
        self.__par=[-1]*n
        self.__length = n

    def root(self,i:int)->int:
        """親ノードを再帰的に探索する
        途中で見つけた親ノードで各子ノード更新する
        Args:
            -  i (int):探したいノード 

        Returns:
            -  int:親ノード
        """
        if self.__par[i]<0:
            return i
        else:
            self.__par[i]=self.root(self.__par[i])
            return self.__par[i]

    def unite(self,a:int,b:int)->None:
        """ノードaとノードbを結合する

        Args:
            -  a (int): 結合したいノード
            -  b (int): 結合したいノード
        """
        b,a=self.root(b),self.root(a)
        if a==b:
            return
        if b<a:
            self.__par[a] += self.__par[b]
            self.__par[b] = a
        else:
            self.__par[b] += self.__par[a]
            self.__par[a] = b
    
    def update(self):
        """
        update関数
        すべての親を更新し、親配列の中身を返す(遅いため注意)
        """
        result = []
        for i in range(self.__length):
            result.append(self.root(i))
        return result

    def __len__(self):
        """
        サイズ取得関数
        """
        return self.__length




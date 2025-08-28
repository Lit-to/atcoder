class unionFind:
    """
    Union-Find
    頂点を結合した際に連結する要素の親ノードを1つに統一する
    各頂点の親ノードを高速に返す
    """
    def __init__(self,n:int):
        """
        コンストラクタ

        引数:
            n (int):すべて独立したn個ノードとして初期化する
        """
        self.__par=[-1]*n

    def root(self,i:int)->int:
        """親ノードを再帰的に探索する
        途中で見つけた親ノードで各子ノード更新する
        引数:
            i (int):探したいノード 

        戻り値:
            int:親ノード
        """
        if self.__par[i]==-1:
            return i
        else:
            self.__par[i]=self.root(self.__par[i])
            return self.__par[i]

    def unite(self,a:int,b:int)->None:
        """ノードaとノードbを結合する

        引数:
            a (int): 結合したいノード
            b (int): 結合したいノード
        """
        b,a=self.root(b),self.root(a)
        if a==b:
            return
        self.__par[b]=a


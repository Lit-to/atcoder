class UnionFind:
    """
    Union-Find
    頂点を結合した際に連結する要素の親ノードを1つに統一する
    各頂点の親ノードを高速に返す
    """
    def __init__(self,length:int):
        """
        コンストラクタ

        Args:
            -  n (int):すべて独立したn個ノードとして初期化する
        """
        self.parent=[-1]*length
        self.size = length

    def Unite(self,node_A:int,node_B:int)->None:
        """ノードaとノードbを結合する

        Args:
            -  a (int): 結合したいノード
            -  b (int): 結合したいノード
        """
        node_B,node_A=self.__UpdateRoot(node_B),self.__UpdateRoot(node_A)
        if node_A==node_B:
            return
        if node_B<node_A:
            self.parent[node_A] += self.parent[node_B]
            self.parent[node_B] = node_A
        else:
            self.parent[node_B] += self.parent[node_A]
            self.parent[node_A] = node_B
    
    def FetchSize(self,node:int)->int:
        """
        ノードの属するグループのサイズを求める
        Args:
        -   ノード番号
        """
        return self.size[self.__UpdateRoot(node)]


    def __UpdateRoot(self,i:int)->int:
        """親ノードを再帰的に探索する
        途中で見つけた親ノードで各子ノード更新する
        Args:
            -  i (int):探したいノード 
        Returns:
            -  int:親ノード
        """
        if self.parent[i]<0:
            return i
        else:
            self.parent[i]=self.__UpdateRoot(self.parent[i])
            return self.parent[i]




class segmentTree(list):
    def __init__(self,values,default=-1,rule=lambda x,y:max(x,y)):
        """
        初期化関数 これらのデータをもとにセグメント木を構築する。
        self.__rule(x,y)は、x,tのうち優先度が大きいほうの値が返却される関数としてユーザが定義する
        Args:
            -  values (list) :初期化対象の配列
            -  default (int) :初期化設定がなかったときの初期値(更新時に一番更新の優先度が低くなる値) デフォルトは-1
            -  rule (function) :値の更新基準 デフォルトは最大更新 
        Exception:
            -  ValueError:valuesに空配列が指定された場合
        """
        # super().__init__(values)
        self.__value_length=len(values) # 実際の値の長さ
        self.__center=self.__calc_size() # 完全二分木として表す配列の長さの半分(値が格納できる大きさのうち一番小さい値をiとしたときの2^iで、実際の値が入る部分の長さ)
        self.__size=self.__center*2 # MSbの2倍の長さの配列
        self.__data=[default]*(self.__size+2) #1-indexedのための端を追加
        self.__default=default # 初期値
        self.__rule=rule # 値更新ルール
        
        for i in range(self.__value_length):#値の上書き
            self.__data[i+self.__center]=values[i]
        
        self.__struct(2)

    def __struct(self,index:int)->list:
        """
        セグメント木を再帰的に構築する関数
        self.__ruleをここで利用する

        Args:
            -  index (int): 値を代入するインデックス

        Returns:
            -  list: 代入された値を返す
        """
        value=self.__default
        if self.__size<(index<<1):
            return self.__data[index-1]
        else:
            right_value=self.__struct(index*2)
            left_value=self.__struct(index*2-1)
            value=self.__rule(left_value,right_value)
            self.__data[index-1]=value
        return value

    def __calc_size(self):
        """
        セグメント木を構築するためのサイズを計算する。
        完全二分木である必要があるため、2,4,8,16...で一番近いものを選んでサイズを決定する。
        厳密には、(1<=i)を満たす整数のうち、2^iの結果がself.sizeを超える一番小さい値になるように設定する。

        求め方
            -  lengthのMSb(1になっているビットのうち、一番左のもの)を求める。
            -  1をMSb左にビットシフトする。
        Return:
            -  int:サイズ
        """
        length=self.__value_length
        if length <=1:
            return 2
        return 1<<self.__calc_msb(length)

    def __calc_msb(self,num:int):
        """
        MSbを求める。
        本来はここをO(logN)で求める方法があるはずだが、ここでは簡便にO(N)で求める。
        ※要修正
        """
        num-=1
        msb=0
        while num>0:
            msb+=1
            num>>=1
        return msb

    def __check_rule(self, ql:int, qr:int, tl:int, tr:int, k:int):
        """
        (a,b)の区間のうち、(l,r)と被っている部分のルール結果を返す。
        複数区間にまたがっている場合は区間を狭めて再起呼び出しする。
        Args:
            -  a (int): 調査区間の左端
            -  b (int): 調査区間の右端
            -  l (int): 対象区間の左端
            -  r (int): 対象区間の右端
            -  k (int): (l,r)の結果が格納されているインデックス

        Returns:
            _type_: 結果
        """

        # 全く関係ない場合(ノード [l,r] とクエリ [a,b) が重ならない)
        if tr < ql or qr <= tl:
            return self.__default

        # ノード [l,r] がクエリ [a,b) に含まれる場合
        if ql <= tl and tr < qr:
            return self.__data[k]

        # 単一要素ノードの処理
        if tl == tr:
            if ql <= tl < qr:
                return self.__data[k]
            else:
                return self.__default

        mid = (tl + tr) // 2
        left = self.__check_rule(ql, qr, tl, mid, 2*k)
        right = self.__check_rule(ql, qr, mid+1, tr, 2*k+1)
        return self.__rule(left, right)

    ### 組み込み系対応関数

    def __len__(self):
        """
        len()が呼び出されたときの関数
        __value_length、つまり初期化時の配列長を返す
        Returns:
            -  int: 配列長
        """
        return self.__value_length
    
    def __str__(self):
        """
        str()が呼び出されたときの関数
        配列をstr()したものを返す

        Returns:
            -  str: 配列をstr()したもの
        """
        return str(self.__data[self.__value_length+1:self.__center+self.__value_length])

    def __getitem__(self,item:slice|int):
        """
        配列にスライスやインデックスの読み出しをする関数
        list[x]のように指定したときに呼び出される
        初期化時の配列(list型)と同様の挙動をする

        Args:
            -  item (slice | int): list[x]のxにあたるインデックス(1-indexed)

        Returns:
            int: 読みだしたデータの内容
        """
        if type(item)==int:
            if 0<=item:
                return self.__data[self.__value_length+item]
            else:
                return self.__data[self.__value_length+self.__center+item]
        else:
            start,stop,step=item.start,item.stop,item.step
            if start==None:
                start=1
            if stop==None:
                stop=self.__value_length
            if step==None:
                step=1
            return self.__data[self.__center+start-1:self.__center+stop-1:step]

    def __setitem__(self,key:int,value:int):
        """
        値の更新を行う

        Args:
            -  key (int): インデックス(1-indexed)
            -  value (int):更新する値 
        """
        self.update(key,value)


    ###セグメント木らしい関数↓

    def update(self,index:int,value:int):
        """
        配列のindex番目にvalueを代入し木の更新を行う。

        Args:
            -  index (int): 代入したい位置を示すインデックス
            -  value (int): 代入したい値
        """
        assert 0<=index<=self.__value_length,"illigal index("+str(index)+")"
        index+=self.__center-1
        self.__data[index]=value
        NEIGHBOR=[-1,1]
        while 2<=index:
            next=index>>1
            diff=NEIGHBOR[index%2==0]
            new_value=self.__rule(self.__data[index],self.__data[index+diff])
            self.__data[next]=new_value
            index=next

    def get_query(self, left:int, right:int):
        """
        (left:right)のうち、self.__ruleの優先順位が一番高い値を返す

        Args:
            -  left (int): 区間のインデックスの左端
            -  right (int): 区間のインデックスの右端
        """
        # 半開区間仕様に合わせてアサートを更新
        assert 1 <= left < right, "left < right 且つ left >= 1 が必要です"
        assert right <= self.__value_length + 1, "right は value_length+1 以下である必要があります"
        return self.__check_rule(left, right, 1, self.__center, 1)


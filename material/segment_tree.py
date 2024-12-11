class segmentTree(list):
    def __init__(self,values,default=-1,rule=lambda x,y:max(x,y)):
        """
        初期化関数 これらのデータをもとにセグメント木を構築する。
        self.rule(x,y)は、x,tのうち優先度が大きいほうの値が返却される関数としてユーザが定義する
        Args:
            values (list) :初期化対象の配列
            default (int) :初期化設定がなかったときの初期値(更新時に一番更新の優先度が低くなる値) デフォルトは-1
            rule (function) :値の更新基準 デフォルトは最大更新 
        Exception:
            ValueError:valuesに空配列が指定された場合
        """
        # super().__init__(values)
        self.value_length=len(values)
        self.half_size=self.__calc_size()      
        self.size=self.half_size*2
        self.data=[default]*(self.size+2) #1-indexedのための端を追加
        self.default=default
        self.rule=rule

        for i in range(self.value_length):#値の上書き
            self.data[i+self.half_size]=values[i]
        
        self.__struct(2)

    def __struct(self,index:int):
        """
        セグメント木を再帰的に構築する関数
        self.ruleをここで利用する

        Args:
            index (int): 値を代入するインデックス

        Returns:
            _type_: 代入された値を返す
        """
        value=self.default
        if self.size<(index<<1):
            return self.data[index-1]
        else:
            right_value=self.__struct(index*2)
            left_value=self.__struct(index*2-1)
            value=self.rule(left_value,right_value)
            self.data[index-1]=value
        return value

    def __calc_size(self):
        """
        セグメント木を構築するためのサイズを計算する。
        完全二分木である必要があるため、2,4,8,16...で一番近いものを選んでサイズを決定する。
        厳密には、(1<=i)を満たす整数のうち、2^iの結果がself.sizeを超える一番小さい値になるように設定する。

        求め方:
            lengthのMSb(1になっているビットのうち、一番左のもの)を求める。
            1をMSb左にビットシフトする。
        """
        length=self.value_length
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

    def __check_rule(self,a:int,b:int,l:int,r:int,k:int):
        """
        (a,b)の区間のうち、(l,r)と被っている部分のルール結果を返す。
        複数区間にまたがっている場合は区間を狭めて再起呼び出しする。
        Args:
            a (int): 調査区間の左端
            b (int): 調査区間の右端
            l (int): 対象区間の左端
            r (int): 対象区間の右端
            k (int): (l,r)の結果が格納されているインデックス

        Returns:
            _type_: 結果
        """
        if b<l or r<a: # 対象外範囲の場合はルール最弱の値を返す
            return self.default
        elif a<=l and r<=b:#この時点で答えが確定している場合は答えを返す
            return self.data[k]
        elif r==l: # lrがぶつかってしまった場合は区間内にいるかどうかをチェック
            if a<=r and r<=b: #区間内の場合は今見える値を返す
                return self.data[k]
            else: #区間外の場合はルール最弱の値を返す
                return self.default
        
        # 以下、範囲が調べたい範囲の境界線を踏んでいる場合
        # 今の区間では判断できないので細分して再起呼び出しで判断する
        left=self.__check_rule(a,b,l,l+(r-l)//2,2*k) 
        right=self.__check_rule(a,b,l+1+(r-l)//2,r,2*k+1)
        return self.rule(left,right)
    
    def update(self,index:int,value:int):
        """
        配列のindex番目にvalueを代入し木の更新を行う。

        Args:
            index (int): 代入したい位置を示すインデックス
            value (int): 代入したい値
        """
        assert 0<=index<=self.value_length,"illigal index("+str(index)+")"
        index+=self.half_size-1
        self.data[index]=value
        NEIGHBOR=[-1,1]
        while 2<=index:
            next=index>>1
            diff=NEIGHBOR[index%2==0]
            new_value=self.rule(self.data[index],self.data[index+diff])
            self.data[next]=new_value
            index=next

    def get_query(self,left:int,right:int):
        """
        (left:right)のうち、self.ruleの優先順位が一番高い値を返す

        Args:
            left (int): 区間のインデックスの左端
            right (int): 区間のインデックスの右端
        """
        assert left<right , "left value needs lower than right"
        assert 0<=left , "left value needs more than 0"
        assert right<=self.value_length , "right value needs lower than max length"
        return self.__check_rule(left,right,1,self.half_size,1)

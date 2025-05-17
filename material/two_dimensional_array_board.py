class Board():

    ROTATE_0_DEGREE = 0
    ROTATE_90_DEGREE = 1
    ROTATE_180_DEGREE = 2
    ROTATE_270_DEGREE = 3
    """
    二次元ボードを便利に使いやすくするためのクラス
    """ 
    def __init__(self,board_data:list):
        """
        インスタンス生成関数
        引数:
            board_data(list):生成する元となる二次元配列データ
        """
        self.__data=[]
        self.__height=len(board_data)
        assert 0<self.__height #高さが0以下だった場合はボードの作りようがないためエラー
        self.__weight=len(board_data[0])
        for i in range(self.__height):
            assert len(board_data[i])==self.__weight #幅がぶれているとこのクラスでは扱えないためエラー
            self.__data.append(board_data[i])
        self.__cells=self.__height*self.__weight

    def get_height(self):
        """
        heightの値を返す関数

        戻り値:
            int:heightの値
        """

    def get_weight(self):
        """
        weightの値を返す関数

        戻り値:
            int:weightの値
        """


    def __len__(self):
        """
        len()を使うための関数
        レコードの数を返す

        戻り値:
            int:二次元配列のレコードの数
        """
        return self.__cells
    
    
    def __getitem__(self,pos:tuple):
        """
        board[]を利用するための関数
        レコードの値を取り出す

        引数:
            (y,x)形式の座標を表すタプル
        戻り値:
            any:テーブルのy行目j列目の値
        """
        return self.__data[pos[0]][pos[1]]
    
    def look(self,pos:tuple):
        """
        レコードの値を取り出す関数

        引数:
            pos(tuple):(y,x)形式の座標を表すタプル
        戻り値:
            any:テーブルのy行目j列目の値        
        """        
        return self[pos]

    def __str__(self):
        """
        str()で呼び出される関数
        いい感じに整形して出力する
        戻り値:
            str:いい感じに整形された二次元配列の文字列
        """
        datas=[]
        sep_count=0
        for i in range(self.__height):
            
            item=" | ".join(str(j) for j in self.__data[i])
            datas.append(item)
            sep_count=max(sep_count,len(item))
            if i==self.__height-1:
                sep="\n"+"-"*sep_count+"-\n"
        return sep.join(datas)

    def set(self,pos,value):
        """
        値を代入する関数
        引数:
            pos(tuple):(y,x)形式の座標を表すタプル
            value(any):代入する値
        """
        self[pos]=value

    def __setitem__(self,pos,value):
        """
        board[pos]=valueを使えるようにするための関数
        値を代入する
        引数:
            pos(tuple):(y,x)形式の座標を表すタプル
            value(any):代入する値
        """
        self.__data[pos[0]][pos[1]]=value

    def is_inside_positive(self,pos):
        """
        正の整数の範囲内で指定のposがボードの内側に含まれているかどうかを返す関数
        
        Args:
            pos (tuple): (y,x)形式の座標を表すタプル
        """
        y,x=pos
        return y<self.__height and x<self.__weight

    def is_inside_negative(self,pos):
        """
        負の整数の範囲内で指定のposがボードの内側に含まれているかどうかを返す関数
        
        Args:
            pos (tuple): (y,x)形式の座標を表すタプル
        """
        y,x=pos
        return -1*self.__weight<=x and -1*self.__height<=y
    

    def is_inside(self,pos):
        """
        指定のposがボードの内側に含まれているかどうかを返す関数
        ただし、マイナスを許容する
        引数:
            pos(tuple):(y,x)形式の座標を表すタプル
        戻り値:
            bool:含まれているか否か
        """
        return self.is_inside_positive(pos) or self.is_inside_negative(pos)

    def rotate(self,degree:int):
        """
        ボードを回転させる関数
        引数:
            degree(int):90の倍数
        """
        if degree%4==1 or degree%4==-3:
            self.__data = [list(g) for g in zip(*self.__data[::-1])]
            self.__height,self.__weight=self.__weight,self.__height
        elif degree%4==2 or degree%4==-2:
            self.__data = [list(g)[::-1] for g in self.__data[::-1]]
        elif degree%4==3 or degree%4==-1:
            self.__data = [list(g) for g in zip(*self.__data)][::-1]
            self.__height,self.__weight=self.__weight,self.__height

    def flip_by_vertical(self):
        """
        ボードを縦方向の線対称に回す
        """
        self.__data = [list(g)[::-1] for g in self.__data]
    
    def flip_by_holizontal(self):
        """
        ボードを横方向の線対称に回す
        """
        self.__data = [list(g) for g in self.__data[::-1]]
    
    def flip(self,vertical=False,horizontal=False):
        """
        ボードを縦か横か指定した方向の線対称に回す
        引数:
            vertical(bool):初期値はFalseで、Trueにすると縦方向に回す
            horizontal(bool):初期値はFalseで、Trueにすると横方向に回す
        """
        if vertical:
            self.flip_by_vertical()
        if horizontal:
            self.flip_by_holizontal()

    def copy(self):
        """
        コピー関数
        戻り値:
            別インスタンスで、中身が同じボードクラス
        """
        data=[]
        for i in range(self.__height):
            data.append(self.__data[i].copy())
        return self.__class__(data)

    def fill(self,value):
        """
        初期化関数
        valueで指定した値でボードのすべてを埋める
        引数:
            value(any):埋めたい値
        """
        for i in range(self.__height):
            for j in range(self.__weight):
                self.__data[i][j] = value

    def add_wall(self,value):
        """
        ATフィールド関数
        valueで指定した値でボードの右端と下端をひとつ増やす。
        引数:
            value(any):増やしたい値
        """
        for i in range(self.__height):
            self.__data[i].append(value)
        self.__weight+=1
        self.__height+=1
        self.__data.append([value]*(self.__weight))
    


# 自作ボードクラスのショートカット関数  
def input_board(height:int,f=lambda:input(list())):
    """
    標準入力からボード作成
    引数:
        height(int):高さ
        f(function):入力の形式 指定しなかった場合は自動で
            スペースのない文字列を想定した入力になる
    戻り値
        Board:作成されたボードクラス
    """
    board=[]
    for i in range(height):
        board.append(f())
    return Board(board)

def input_board_with_wall(height:int,weight:int,wall:any,f:lambda x:input(list())):
    """
    標準入力からボード作成(ATフィールド付)
    引数:
        height(int):高さ
        weight(int):幅
        wall:壁に割り当てる値
        f(function):入力の形式 指定しなかった場合は自動で
            スペースのない文字列を想定した入力になる
    戻り値
        Board:作成されたボードクラス
    """
    board=[]
    for i in range(height):
        board.append(f()+[wall])
    board.append([wall]*(weight+1))
    return Board(board)

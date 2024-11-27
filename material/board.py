class Board:
    # ボードを使いやすくするクラス
    # 初期化時にコンストラクタでサイズHWと初期値を指定する
    # 中身のボードは一次元配列で定義する
    # W個ごとに並べる
    # board.get_height(i,j)で値を取得
    # 範囲外の場合はエラーとして落とす
    # board.set_height(i,j)で値を代入
    # 範囲外の場合はエラーとして落とす
    # board.heightでHの値を返す
    # board.weightでWの値を返す

    def __init__(
        self, h: int, w: int, default: int | str | bool, can_loop: bool = True
    ) -> None:  # 初期化 ※defaultはイミュータブルなものである必要がある
        self.__board = [default] * (h * w) #データ
        self.__height = h #高さ
        self.__weight = w #幅
        self.can_loop=can_loop #ループを許容するか(デフォルトはTrue)


    def get_height(self) -> int:  # Hの値を取得
        return self.__height

    def get_width(self) -> int:  # Wの値を取得
        return self.__weight

    def get_index(self, i: int, j: int) -> int:  # i,jの情報から座標を計算する
        if self.can_loop:
            assert (
                -1 * self.get_height() <= i and i < self.get_height()
            ), "IndexError: list index out of range"
            assert (
                -1 * self.get_width() <= j and j < self.get_width()
            ), "IndexError: list index out of range"
            if i < 0:
                i += self.get_height()
            if j < 0:
                j += self.get_width()
        else:
            assert (
                0 <= i and i < self.get_height() and 0 <= j and j < self.get_width()
            ), "IndexError: list index out of range"
        return i * self.get_width() + j  # i*W+jが一次元における指定マスの場所

    def get_pos(self,index:int):
        i=index//self.get_width()
        j=index%self.get_width()
        return i,j

    def get_value(self, i: int, j: int) -> int | str | bool:
        pos = self.get_index(i, j)
        return self.__board[pos]

    def set_value(self, i: int, j: int, value: int | str | bool) -> None:
        pos = self.get_index(i, j)
        self.__board[pos] = value

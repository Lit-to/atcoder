

class Board:
    # ボードを使いやすくするクラス
    # 初期化時にコンストラクタでサイズHWと初期値を指定する
    # 中身のボードは一次元配列で定義する
    # W個ごとに並べる
    # board.get(i,j)で値を取得
    # board.set(i,j)で値を代入
    # 0<=i<H 0<=j<W を満たさなかった場合はエラーとして落とす
    # board.heightでHの値を返す
    # board.weightでWの値を返す

    def __init__(self, h, w, default):
        self.__board = [default] * (h * w)
        self.__height = h
        self.__weight = w

    def get_height(self):
        return self.__height

    def get_width(self):
        return self.__weight

    def __get_pos(self, i, j):
        # assert 0<=i<self.get_height() and 0<=j<self.get_weight(),"IndexError: list index out of range"
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
        return i * self.get_width() + j

    def get_value(self, i, j):
        pos = self.__get_pos(i, j)
        return self.__board[pos]

    def set_value(self, i, j, value):
        pos = self.__get_pos(i, j)
        self.__board[pos] = value


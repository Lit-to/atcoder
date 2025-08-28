class BoardUtility:
    """
    二次元配列系の便利関数総集
    """

    def rotate90(grid:list) -> list:
        """配列を90度回転させる

        引数:
            grid (list): 全て要素が入った二次元配列

        戻り値:
            list: 90度回転させた二次元配列
        """
        return [list(g) for g in zip(*grid[::-1])]

    def rotate_reverse90(grid:list) -> list:
        """配列を反時計回りに90度回転させる

        引数:
            grid (list): 全て要素が入った二次元配列

        戻り値:
            list: 反時計回りに90度回転させた二次元配列
        """
        return [list(g) for g in zip(*grid)][::-1]

    def rotate180(grid:list) -> list:
        """配列を反時計回りに180度回転させる

        引数:
            grid (list): 全て要素が入った二次元配列

        戻り値:
            list: 反時計回りに180度回転させた二次元配列
        """
        return [list(g)[::-1] for g in grid[::-1]]

    def flip_by_holizontal(grid:list) -> list:
        """配列を横軸に線対称へ移動させる

        引数:
            grid (list): 全て要素が入った二次元配列

        戻り値:
            list: 横軸に線対称移動させた二次元配列
        """
        return [list(g) for g in grid[::-1]]

    def flip_by_vertical(grid:list) -> list:
        """配列を縦軸に線対称へ移動させる

        引数:
            grid (list): 全て要素が入った二次元配列

        戻り値:
            list: 線対称へ移動させた二次元配列
        """
        return [list(g)[::-1] for g in grid]

    def look(pos: tuple, board: list)->int:
        """
        引数:
            pos (tuple): 座標
            board (list): 調べたい二次元ボード

        戻り値:
            int: 結果
        """
        return board[pos[0]][pos[1]]

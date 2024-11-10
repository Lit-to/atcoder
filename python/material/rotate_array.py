class RotateArray: #二次元配列の回転
    ## 時計回りに90度
    def rotate90(grid):
        return [list(g) for g in zip(*grid[::-1])]
    ## 反時計回りに90度
    def rotate_reverse90(grid):
        return [list(g) for g in zip(*grid)][::-1]
    ## 180度
    def rotate180(grid):
        return [list(g)[::-1] for g in grid[::-1]]
    ## 横軸に線対称
    def flip_by_holizontal(grid):
        return [list(g) for g in grid[::-1]]
    ## 縦軸に線対称
    def flip_by_vertical(grid):
        return [list(g)[::-1] for g in grid]


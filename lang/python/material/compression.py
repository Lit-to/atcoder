def compression(A: list) -> list:
    """座標圧縮
    座標を左上に詰める。
    Aをコピー、重複を消し、ソートする。

    Args:
        A (list): 圧縮する配列が入ったリスト

    Returns:
        list: 圧縮結果
    """
    B = sorted(list(set(A.copy())))
    result = []  # 結果となるべき配列
    for i in A:
        result.append(index(B, i))  # Aの要素がBのうち何番目にあたるかを返す
    return result


def index(a: list, i: int) -> int:  # 簡易二分探索
    # 二分探索で配列の中のiが何番目にあるかを返す
    f = lambda x: a[x] <= i
    ok = -1
    ng = len(a)
    while 1 < abs(ok - ng):
        mid = (ng + ok) // 2
        if f(mid):
            ok = mid
        else:
            ng = mid
    else:
        return ok

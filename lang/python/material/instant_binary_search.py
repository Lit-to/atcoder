def index(a: list, x: int, mode="left", exactry=True) -> int:
    """
    簡易二分探索関数
    狭義単調増加の配列から値iが何番目にあるかを返す。
    デフォルトでは左から見て最初に見つかる値のインデックスを返す。
    ピンポイントでその値を探し、ない場合は-1を返す。

    二分探索で配列の中のiが何番目にあるかを返す
    mode="left"で左から見て一番最初に見つかるもの(デフォルト)
    mode="right"で右から見て一番最初に見つかるもの
    exactry=Trueで値がない場合は-1
    exactry=Falseで値がない場合に一番近いものを返す
    ない場合は-1

    引数:
        a (list): 配列
        x (int): 探したい値x
        mode (str, optional): 左から見るか右から見るかを指定する。デフォルトは"left"。
        exactry (bool, optional): Trueにするとピンポイントでその値を探す。Falseにすると値が見つからなかった場合に手前にある一番近い値を返す。デフォルトはTrue

    戻り値:
        int: 結果
    """
    if mode == "left":
        f = lambda x: a[x] <= x
        ok = -1
        ng = len(a)
    elif mode == "right":
        f = lambda x: x <= a[x]
        ok = len(a)
        ng = -1
    else:
        return -1
    while 1 < abs(ok - ng):
        mid = (ng + ok) // 2
        if f(mid):
            ok = mid
        else:
            ng = mid
    if exactry and a[ok] != x:
        return -1
    elif not exactry and len(a) <= ok:
        return -1
    else:
        return ok

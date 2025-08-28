def search(ok:int,ng:int,f:bool)->int:
    """二分探索を行う関数
    単調増加の範囲においてokのうちいちばんngに近いものの値を返す
    lambda i:a[i]<x xを含まない最大のiを返す
    lambda i:a[i]<=x xを含む最大のiを返す

    Args:
        ok (int): 評価関数fに渡したときに必ずTrueを返すことが保証されている値
        ng (int): 評価関数fに渡したときに必ずFalseを返すことが保証されている値
        f (bool): 評価関数(引数1/戻り値bool)

    Returns:
        int: 結果
    """
    while 1<abs(ok-ng):
        mid=(ng+ok)//2
        if f(mid):
            ok=mid
        else:
            ng=mid
    return ok

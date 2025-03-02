
def search(ok:int,ng:int,f:bool)->int:
    """
    二分探索イデア
    広義単調増加もしくは広義単調減少のok~ngの範囲内で、評価関数fがTrueになる一番ngに近い値を返す。  

    評価関数の例:
        lambda i:a[i]<x xを含まない最大のiを返す
        lambda i:a[i]<=x xを含む最大のiを返す   

    Args:
        ok (int): 少なくとも評価関数fがTrueになる値
        ng (int): 少なくとも評価関数fがFalseになる値
        f (bool): 引数を1つもらう評価関数

    Returns:
        int: okとngが隣り合ったときのokの値
    """
    while 1<abs(ok-ng):
        mid=(ng+ok)//2
        if f(mid):
            ok=mid
        else:
            ng=mid
    return ok

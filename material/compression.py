def compression(A:list)->list:
    """
    座標圧縮テンプレート
    
    Args:
        A (list): 対象配列

    Returns:
        list: 加工後の配列
    """
    
    # 座標圧縮：配列の座圧(配列を渡して圧縮した座標を返す)
    B=sorted(list(set(A.copy())))
    result=[] # 結果となるべき配列
    for i in A:
        result.append(index(B,i)) # Aの要素がBのうち何番目にあたるかを返す
    return result

def index(a:list,i:int)->int:
    f=lambda x: a[x]<=i
    ok=-1
    ng=len(a)
    while 1<abs(ok-ng):
        mid=(ng+ok)//2
        if f(mid):
            ok=mid
        else:
            ng=mid
    else:
        return ok

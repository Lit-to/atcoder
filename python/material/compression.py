def compression(A:list)->list:#座標圧縮：配列の座圧(配列を渡して圧縮した座標を返す)
    B=sorted(list(set(A.copy())))#BにAのコピーをし、重複を消し、ソートしたもの
    result=[]#結果となるべき配列
    for i in A:
        result.append(index(B,i))#Aの要素がBのうち何番目にあたるかを返す
    return result
def index(a:list,i:int)->int: #簡易二分探索
    #二分探索で配列の中のiが何番目にあるかを返す
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

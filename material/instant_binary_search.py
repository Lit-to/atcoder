def index(a:list,i:int,mode="left",exactry=True)->int:
    #二分探索で配列の中のiが何番目にあるかを返す
    #mode="left"で左から見て一番最初に見つかるもの(デフォルト)
    #mode="right"で右から見て一番最初に見つかるもの
    #exactry=Trueで値がない場合は-1
    #exactry=Falseで値がない場合に一番近いものを返す
    #ない場合は-1
    if mode=="left":
        f=lambda x: a[x]<=i
        ok=-1
        ng=len(a)
    elif mode=="right":
        f=lambda x: i<=a[x]
        ok=len(a)
        ng=-1
    else:
        return -1
    while 1<abs(ok-ng):
        mid=(ng+ok)//2
        if f(mid):
            ok=mid
        else:
            ng=mid
    if exactry and a[ok]!=i:
        return -1
    elif not exactry and len(a)<=ok:
        return -1
    else:
        return ok

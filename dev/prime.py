def prime(num:int) -> list:
    """素因数分解の結果を返す
    ※利用するためには import mathが必須
    
    Args:
        num (int): 合成数または素数

    Returns:
        list: 分解した素数を返す
    """
    result=[]
    while num%2==0:
        num//=2
        result.append(2)
    c=3
    while c<=math.sqrt(num):
        if num%c==0:
            num//=c
            result.append(c)
        else:
            c+=2
    if num!=1:
        result.append(num)
    return result

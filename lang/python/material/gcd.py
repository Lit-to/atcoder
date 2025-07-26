def gcd(value_a:int,value_b:int)->int:
    """互除法で最大公約数を求める関数

    Args:
        value_a (int): 求めたい値A
        value_b (int): 求めたい値B

    Returns:
        int: AとBの最大公約数
    """
    if value_a<value_b:
        value_a,value_b,value_b,value_a
    while value_b!=0:
        temp=value_b
        value_b=value_a%value_b
        value_a=temp
    return value_a



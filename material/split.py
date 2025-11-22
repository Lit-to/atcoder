def split(value:str,sep:str=" ",func:callable=str) -> list:
    """
    分割関数
    文字列をスペース区切りで分割する。
    """
    result = []
    if sep == "":
        result = list(value)
    else:
        section = 0
        for i in range(len(value)):
            if value[i] == sep:
                result.append(value[section:i])
                section = i
        if section != i:
            result.append(value[section:])

    for i in range(len(result)):
        result[i] = func(result[i])
    return result

if __name__ == "__main__":
    test = "aaaa bbb 122ccc d3257dddd"
    print(split(test))
    test = "aaaa bbb 122ccc d3257ddd d"
    print(split(test))
    test = "123 233 352 43632 32"
    print(split(test,func=int))
    test = "wejhfeoiwqjgqoijfgqoigjeqo"
    print(split(test,sep=""))
    test = "12345678654324567"
    print(split(test,"",int))



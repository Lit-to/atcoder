def runLengthEncode(s:str|list) -> list:
    """
    ランレングスエンコードを行う
    要素ごとに分解し、要素と個数のタプル組にする(そのため厳密には圧縮されてはいない)。
    同一の要素がある場合後ろを削除し、手前側の個数に+1する。

    引数:
        s (str | list):エンコードしたい文字列 

    戻り値:
        list: 圧縮後の配列
    """
    l=len(s)
    result=[]
    if l==0:
        return result
    now=[s[0],0]
    for i in range(l):
        if s[i]==now[0]:
            now[1]+=1
        elif s[i]!=now[0]:#更新
            result.append(tuple(now))
            now=[s[i],1]
    result.append(tuple(now))
    return result
def runLengthDecode(data:list)->list:
    """
    ランレングス復号
    要素と個数のタプルが入ったリストをすべての要素で個数個展開する

    引数:
        data (list): 要素と個数のタプルが入ったリスト

    戻り値:
        list: 復号後のリスト
    """
    result=""
    for i in data:
        result+=i[0]*i[1]
    return result

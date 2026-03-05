class LitUtility:
    def Search(ok:int,ng:int,f:bool)->int:
        """二分探索を行う関数
        単調増加の範囲においてokのうちいちばんngに近いものの値を返す
        利用例:
        -  lambda i:a[i]<x xを含まない最大のiを返す
        -  lambda i:a[i]<=x xを含む最大のiを返す

        Args:
            -  ok (int): 評価関数fに渡したときに必ずTrueを返すことが保証されている値
            -  ng (int): 評価関数fに渡したときに必ずFalseを返すことが保証されている値
            -  f (bool): 評価関数(引数1/戻り値bool)

        Returns:
            -  int: 結果
        """
        while 1<abs(ok-ng):
            mid=(ng+ok)//2
            if f(mid):
                ok=mid
            else:
                ng=mid
        return ok

    def Compression(A: list) -> list:
        """座標圧縮
        座標を左上に詰める。
        Aをコピー、重複を消し、ソートする。

        Args:
            -  A (list): 圧縮する配列が入ったリスト

        Returns:
            -  list: 圧縮結果
        """
        B = sorted(list(set(A.copy())))
        result = []  # 結果となるべき配列
        for i in A:
            result.append(LitUtility.Index(B, i))  # Aの要素がBのうち何番目にあたるかを返す
        return result


    def Index(a: list, i: int) -> int:  # 簡易二分探索
        # 二分探索で配列の中のiが何番目にあるかを返す
        # →二分探索モジュールと同様のためドキュメント不在
        f = lambda x: a[x] <= i
        ok = -1
        ng = len(a)
        while 1 < abs(ok - ng):
            mid = (ng + ok) // 2
            if f(mid):
                ok = mid
            else:
                ng = mid
        else:
            return ok

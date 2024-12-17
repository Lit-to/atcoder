class prefix_sum(tuple):
    def __init__(self, value: list, reverse: bool = False):
        super().__init__()
        data=[0]
        for i in value:
            data.append(self[-1] + i)
        data.reverse if reverse else None
        self = tuple(data)

    def get_sum(self, left: int, right: int):
        """半開区間[l,r)の総和を取得する。

        Args:
            left (int): 左端
            right (int): 右端

        Returns:
            int: 総和の結果
        """
        return self[right] - self[left]


if __name__ == "__main__":
    N, Q = map(int, input().split())
    A = list(map(int, input().split()))
    QUERY = []
    for i in range(Q):
        QUERY.append(tuple(map(lambda x:int(x)-1, input().split())))
    A_ = prefix_sum(A)
    for l, r in QUERY:
        print(A_.get_sum(l,r+1))


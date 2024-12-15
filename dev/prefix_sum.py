class prefix_sum(list):
    def __init__(self, value: list, reverse: bool = False):
        super().__init__(self)
        step = -1 if reverse else 1
        for i in [0]+value[::step]:
            self.append(self[-1] + i)
        self = tuple(self)

    def get_sum(self, left: int, right: int):
        """開区間[l,r]の総和を取得する。

        Args:
            left (int): 左端
            right (int): 右端

        Returns:
            int: 値
        """
        return self[right] - self[left]


if __name__ == "__main__":
    N, Q = map(int, input().split())
    A = list(map(int, input().split()))
    QUERY = []
    for i in range(Q):
        QUERY.append(tuple(map(int, input().split())))
    A_ = prefix_sum(A)
    for l, r in QUERY:
        print(A_[r] - A_[l])

class factrial:
    def __init__(self):
        self.table = dict()
        self.key = 1
        self.table[1] = 1

    def calc(self, n: int):
        result = self.table[self.key]
        while self.key < n:
            self.key += 1
            result *= self.key
            self.table[self.key] = result
        return result

    def check(self, n: int):
        return n < self.key

    def __len__(self):
        return len(self.table)

    def factrial(self, n: int):
        if n < 0:
            raise ValueError
        elif n <= 1:
            return 1
        elif self.check(n):
            return self.table[n]
        else:
            return self.calc(n)

    def f(self, n: int):
        return self.factrial(n)


if __name__ == "__main__":
    fact = factrial()
    print(fact.f(40))
    print(fact.f(11))

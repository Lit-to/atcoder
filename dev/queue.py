class queue:

    def __init__(self):
        self.data = []
        self.begin = 0
        self.end = 0

    def __len__(self):
        return self.end - self.begin

    def __str__(self):
        return str(self.data[self.begin:self.end])

    def isEmpty(self):
        return 0<len(self)

    def push(self,value):
        self.data[self.end] = value
        self.end += 1

    def pop(self):
        self.begin += 1
    
    def top(self):
        return self.data[self.begin]

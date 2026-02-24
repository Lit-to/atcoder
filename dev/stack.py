class stack:

    def __init__(self):
        self.data = []
        self.begin = 0
        self.end = 0

    def __len__(self):
        return self.end - self.begin

    def __str__(self):
        return str(self.data[self.begin:self.end])

    def isEmpty(self):
        return len(self) == 0

    def push(self,value):
        if len(self.data) <= self.end:
            self.data.append(-1)
        self.data[self.end] = value
        self.end += 1

    def pop(self):
        self.end -= 1
    
    def top(self):
        return self.data[self.end - 1]

    def rebuild(self):
        return stack(self.data[self.begin(),self.end()])


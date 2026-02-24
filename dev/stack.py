class stack:

    def __init__(self):
        self.data = []
        self.begin = 0
        self.end = 0

    def __len__(self):
        return self.end - self.begin

    def __str__(self):
        return str(self.data[self.begin:self.end])

    def IsEmpty(self):
        return len(self) == 0

    def Push(self,value):
        if len(self.data) <= self.end:
            self.data.append(-1)
        self.data[self.end] = value
        self.end += 1

    def Pop(self):
        self.end -= 1
    
    def GetBack(self):
        return self.data[self.end - 1]

    def Rebuild(self):
        return stack(self.data[self.begin():self.end()])


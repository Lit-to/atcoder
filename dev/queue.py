class queue:

    def __init__(self):
        self.data = []
        self.begin = 0
        self.end = 0

    def __len__(self):
        return self.end - self.begin

    def __str__(self):
        return str(self.data[self.begin:self.end])

    def IsEmpty(self):
        return len(self)==0

    def Enqueue(self,value):
        self.data.append(value)
        self.end += 1

    def Dequeue(self):
        self.begin += 1
    
    def GetFront(self):
        return self.data[self.begin]

    def Rebuild(self):
        return queue(self.data[self.begin(),self.end()])

# 2026-02-25 16:15:43
class Queue:

    def __init__(self):
        self.__data = []
        self.__begin = 0
        self.__end = 0

    def __len__(self):
        return self.__end - self.__begin

    def __str__(self):
        return str(self.__data[self.__begin:self.__end])
    
    def __getitem__(self, key):
        if not self.__begin+key < self.__end:
            raise IndexError
        return self.__data[self.__begin+key]

    def IsEmpty(self):
        return len(self)==0

    def Enqueue(self,value):
        self.__data.append(value)
        self.__end += 1

    def Dequeue(self):
        if self.IsEmpty():
            raise IndexError("list index out of range") 
        self.__begin += 1
    
    def GetFront(self):
        if self.IsEmpty() == False:
            return self.__data[self.__begin]

    def Rebuild(self):
        self.__data = self.__data[self.__begin:self.__end]
        self.__begin = 0
        self.__end = len(self.__data)

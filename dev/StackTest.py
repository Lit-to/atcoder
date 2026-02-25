# 2026-02-25 16:15:43
class Stack:

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
        return len(self) == 0

    def Push(self,value):
        if len(self.__data) <= self.__end:
            self.__data.append(-1)
        self.__data[self.__end] = value
        self.__end += 1

    def Pop(self):
        if (self.IsEmpty()):
            raise IndexError("list index out of range")
        self.__end -= 1
    
    def GetBack(self):
        return self.__data[self.__end - 1]

    def Rebuild(self):
        self.__data = self.__data[self.__begin:self.__end]
        self.__begin = 0
        self.__end = len(self.__data)

import random

litStack = Stack()
stlStack = []
testList = [0,0,0,0,0]
for i in range(2*10**5):
    query = random.randint(0,4)
    testList[query] += 1
    if query==0:
        r = random.randint(0,10**9)
        litStack.Push(r)
        stlStack.append(r)
    elif query==1:
        assert len(litStack)==len(stlStack)
        if len(stlStack)!=0:
            litStack.Pop()
            stlStack.pop()
    elif query==2:
        assert len(litStack)==len(stlStack)
        if len(stlStack)!=0:
            r = random.randint(0,len(stlStack)-1)
            assert litStack[r]==stlStack[r]
    elif query==3:
        assert litStack.IsEmpty() == (len(stlStack) == 0)
    else:
        litStack.Rebuild()
    assert str(litStack) == str(stlStack)
print("OK")
print("Log:",testList)




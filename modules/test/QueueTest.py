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
        return self.__data[self.__begin]

    def Rebuild(self):
        self.__data = self.__data[self.__begin:self.__end]
        self.__begin = 0
        self.__end = len(self.__data)

from collections import deque
import random

litQ = Queue()
stlQ = deque()
testList = [0,0,0,0,0]
for i in range(2*10**5):
    query = random.randint(0,4)
    testList[query] += 1
    if query==0:
        r = random.randint(0,10**9)
        litQ.Enqueue(r)
        stlQ.append(r)
    elif query==1:
        assert len(litQ)==len(stlQ)
        if len(stlQ)!=0:
            litQ.Dequeue()
            stlQ.popleft()
    elif query==2:
        assert len(litQ)==len(stlQ)
        if len(stlQ)!=0:
            r = random.randint(0,len(stlQ)-1)
            assert litQ[r]==stlQ[r]
    elif query==3:
        assert litQ.IsEmpty() == (len(stlQ) == 0)
    else:
        litQ.Rebuild()
    assert str(litQ).strip() == str(stlQ).strip()[6:-1]
print("OK")
print("Log:",testList)




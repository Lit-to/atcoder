# 2026-02-25 17:05:10
import sys
import os
sys.path.append(
    os.path.abspath(
        os.path.join(os.path.dirname(__file__), "../../")
    )
)
from modules.py.Queue import Queue
from collections import deque
import random

litQ = Queue()
stlQ = deque()
testCount = 5
testList = [0]*(testCount+1)
for i in range(2*10**5):
    query = random.randint(0,testCount)
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
    elif query==4:
        assert len(litQ)==len(stlQ)
        if len(stlQ)!=0:
            assert litQ.GetFront() == stlQ[0]
    else:
        litQ.Rebuild()
    assert str(litQ).strip() == str(stlQ).strip()[6:-1]
print("OK")
print("Log:",testList)




import heapq
class priorityQueue():#heapqラッパー
    def __init__(self,l=list()):#インスタンス化
        self.queue=l.copy()
        heapq.heapify(self.queue)
    def __getitem__(self,i):
        return self.queue[i]
    def __len__(self):#かぞえる
        return len(self.queue)
    def __str__(self):#出力用
        return str(self.queue)
    def enq(self,value):#入れる
        return heapq.heappush(self.queue,value)
    def add(self,value):#入れる
        return heapq.heappush(self.queue,value)
    def deq(self):#出す
        return heapq.heappop(self.queue)

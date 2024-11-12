class unionFind: #UnionFind
    def __init__(self,n):
        self.par=[-1]*n
    def root(self,i):
        if self.par[i]==-1:
            return i
        else:
            self.par[i]=self.root(self.par[i])
            return self.par[i]
    def unite(self,a,b):
        b,a=self.root(b),self.root(a)
        if a==b:
            return
        self.par[b]=a
    def is_same(self,a,b):
        return self.root(a)==self.root(b)


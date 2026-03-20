import os
class out:
    """
    お気楽ファイル出力クラス
    """
    path:str
    encoding:str
    def __init__(self,path:str,encoding="utf8"):
        self.path = path
        self.encoding= encoding
        with open(self.path,encoding=self.encoding,mode="w") as f:
            print("",file=f,end="")
            
    def print(self,*contents:str):
        with open(self.path,encoding=self.encoding,mode="a") as f:
            print(*contents,file=f)

p=out(os.path.join("test","input","random.txt"))
N,K=1000,5000
p.print(N,K)
p.print(*[1]*1000)
p.print(*[1]*1000)
p.print(*[1]*1000)
p.print(*[1]*1000)
    
    

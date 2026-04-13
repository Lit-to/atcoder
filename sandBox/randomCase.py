import os
import random
from pathlib import Path
os.chdir(Path(__file__).resolve().parent)
class Print:
    """
    @brief ファイル指定での読み書きを楽に行うためのクラス
    お気楽ファイル出力クラス
    """
    path:str # ファイルパス
    encoding:str # 文字コード
    def __init__(self,path:str,encoding:str="utf8"):
        """
        @brief コンストラクタ URLを登録する
        @param path ファイルパス
        @param encoding 文字コード(デフォルト:utf8)
        """
        self.path = path
        self.encoding= encoding
        with open(self.path,encoding=self.encoding,mode="w") as f:
            print("",file=f,end="")
            
    def print(self,*contents:str,sep=" ",end="\n"):
        """
        @brief ファイル出力関数
        @param *contents 出力したい文字列
        @param sep 複数個出力するときの区切り文字(デフォルト:空文字列)
        @param emd 出力後につける文字列(デフォルト:改行文字)
        """
        with open(self.path,encoding=self.encoding,mode="a") as f:
            print(*contents,file=f,sep=sep,end=end)
for test in range(1):
    fm=Print(os.path.join("input","random_"+str(test)+".txt"))
    N,A=1000,100
    x = 0
    queries = []
    for i in range(N):
        y = x
        q,a = ["+","-","*"][random.randint(0,2)],random.randint(1,A)
        if q=="+":
            x+=a
        elif q=="-":
            x-=a
        elif q=="*":
            x*=a
        if 0<=x:
            queries.append((q,a))
        else:
            x = y
    fm.print(len(queries))
    for i in queries:
        fm.print(*i)
    fm.print()
# fm.print(N,K)
# fm.print(*[1]*1000)
# fm.print(*[1]*1000)
# fm.print(*[1]*1000)
    
    

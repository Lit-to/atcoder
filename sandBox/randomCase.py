import os
import random
from pathlib import Path
os.chdir(Path(__file__).resolve().parent)
UPPER_ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
LOWER_ALPHABET="abcdefghijklmnopqrstuvwxyz"
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
for test in range(100):
    fm=Print(os.path.join("input","random_"+str(test)+".txt"))
    n = random.randint(1,20)
    m = random.randint(1,5)
    S = []
    T = []
    for i in range(n):
        S.append(random.choice(list(LOWER_ALPHABET)))
    for i in range(m):
        T.append(random.choice(list(LOWER_ALPHABET)))
    fm.print(*S,sep="")
    fm.print(*T,sep="")

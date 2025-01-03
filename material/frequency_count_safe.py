import sys
if 0<len(sys.argv) and "FREQUENCY" in sys.argv:
    """
        出現頻度カウント用クラスを安全に使うための分岐
        実行時引数に"FREQUENCY"を追加することで動くようになる
        ない場合は全て無視される        
        import sysが必要
    """
    print("頻度計測:True",file=sys.stderr)
    class frequency_count:
        """
        出現頻度カウント用クラス
        デバッグ用に、プログラムのある個所が何回実行されるかをカウントする。
        プログラム終了直前に出力する。
        fileに出力先を設定出来るため、stderrを推奨。
        """
        def __init__(self,*args:str,file=sys.stderr):
            """
            コンストラクタ
            defaultdictをdictで上書きしていない場合はここで定義した名前のみ利用可能。

            Args:
                *args(str):キーとなる名前
                file:出力先
            """
            self.existMAX=False
            self.file=file
            assert 0<len(args)
            self.data=dict()
            self.count=len(args)
            for i in range(self.count):
                if args[i]=="MAX":
                    self.MAX=args[i]
                    self.existMAX=True
                self.data[args[i]]=0

        def __getitem__(self,key):
            """
            カウンタ
            self[key]と呼ぶだけで自動的に1回と数える。

            Args:
                key(int) キー
            """
            self.data[key]+=1

        def __del__(self):
            """
            デストラクタ
            プログラム終了時に内容を出力する。
            MAXというキーが存在しない場合は数のみ、する場合はグラフを出力する。
            """
            if self.existMAX==True:
                mx=self.data[self.MAX]
                print("■"*10," :",self.MAX,self.data[self.MAX],file=self.file)
                for i in self.data:
                    count=self.data[i]
                    if mx==count:
                        print("■"*10," :",i,count,file=self.file)
                    elif mx<count:
                        print("■"*11,":",i,count,file=self.file)
                    else:
                        amount=min(10-int((count/mx)*10),0)
                        print("■"*amount+"□"*(10-amount)," :",i,count,file=self.file)
            else:
                for i in self.data:
                    print(i,":",count,file=self.file)
else:
    class frequency_count:
        def __init__(self,*args,file=""):
            pass
        def __getitem__(self,key):
            pass
        def __del__(self):
            pass
# デバッグ用
FREQUENCY_COUNT=frequency_count("MAX","a","b","c",file=sys.stderr)


# フェネック木を作ろう
# 参考↓超分かりやすい
# https://qiita.com/AkariLuminous/items/f2f7930e7f67963f0493
# https://atcoder.jp/contests/practice2/submissions/61313128
# 要件
# 数列Aを持っている
# クエリとして以下が与えられる
#   add i x:Aのi番目にxを足す
#   sum i  :Aのi番目までの総和を計算する
# 各クエリO(logN)を目指す



class FenewicTree:
    def __init__(self,arg:int|list|tuple):
        if type(arg)==int:
            self.__data=[0]*(arg+1)
            self.__length=arg+1
        elif type(arg)==list or type(arg)==tuple:
            self.__length=len(arg)+1
            self.__data=[0]*self.__length
            for i in range(self.__length-1):
                self.add(i+1,arg[i])

    def __len__(self):
        return self.__length

    def add(self,index,x):
        while index<len(self.__data):
            self.__data[index]+=x
            binary=index
            num=1
            while True:
                if binary%2==1:
                    break
                else:
                    binary>>=1
                    num*=2
            index+=num
        

    def sum(self,index:int):
        if index==0:
            return 0
        result=0
        while 0<index:
            result+=self.__data[index]
            binary=index
            num=1
            while True:
                if binary%2==1:
                    break
                else:
                    binary>>=1
                    num*=2
                    continue
            index-=num
        return result



if __name__=="__main__":
    # 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
    N, Q = map(int,input().split())
    A = list(map(int,input().split()))
    QUERY=[]
    for i in range(Q):
        QUERY.append(tuple(map(int,input().split())))
    

    # 処理スペース ================================================================================================Lit_to
    ft=FenewicTree(A)
    for i in QUERY:
        if i[0]==0:
            q,p,x=i[0],i[1],i[2]
            A[p]+=x
            ft.add(p+1,x)
        else:
            q,l,r=i[0],i[1],i[2]
            print(ft.sum(r)-ft.sum(l))





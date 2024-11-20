# フェネック木を作ろう

# 要件
# 数列Aを持っている
# クエリとして以下が与えられる
#   add i x:Aのi番目にxを足す
#   sum i  :Aのi番目までの総和を計算する
# 各クエリO(logN)を目指す



class FenewicTree:
    def __init__(self,n:int):
        self.data=[0]*n
        self.length=n

    def add(self,index,x):
        if index==0:
            self[index]+=x
        else:
            while 0<index:
                self.data[index]+=x
                binary=list(bin(index))[2:]
                num=1
                while True:
                    if binary.pop()=="1":
                        break
                    else:
                        num*=2
                index-=num
        

    def sum(self):
        result=0
        size=self.length-1
        while 0<size:
            result+=self.data[size]
            binary=list(bin(size)[2:])
            num=1
            while True:
                num*=2
                if binary.pop()=="1":
                    break
                else:
                    continue
            size-=num
        return result



if __name__=="__main__":
    ft=FenewicTree(8)
    print(ft.data)
    ft.add(2,9)
    print(ft.sum())
    # print(ft.sum(0))
    ft.add(3,7)
    ft.add(6,3)
    ft.add(7,4)
    ft.add(2,5)
    print(ft.sum())
    print(ft.data)
    # print(ft.sum(4))

#0,0,0,0,0,0,0,0 =>0 初期
#0,0,9,0,0,0,0,0 =>9 7
#0,0,9,0,0,0,0,0 =>0 0
#0,0,14,7,0,0,3,4 =>28 7
#0,0,14,7,0,0,3,4=>21 4

#0 01 2 0123 4 45 6 4567 01234567
#0  0 0    0 0  0 0    0        0
#0  0 9    9 0  0 0    0        9
#0  0 0    7 0  0 0    0        16
#0  0 0    0 0  0 3    3        19
#0  0 0    0 0  0 0    4        23
#0  0 5    5 0  0 0    0        28















# 入力スペース ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lit_to
# N = int(input())
# H, W = map(int,input().split())
# A = list(map(int,input().split()))
# S = input()
# S = list(input())
# S = list(input().split())
# BOARD = [list(input()) for i in range(H)]#文字列のリスト
# BOARD = [list(map(int,input().split())) for i in range(H)]#数値のリスト
# A = list(map(lambda x:int(x)-1,input().split())) # 0-indexedで値を取得
# A = map(lambda x:x,sorted(list(map(int,(input().split())))))#数の組み合わせを並び替えて渡す
# debug("======output is start======")
# 処理スペース ================================================================================================Lit_to












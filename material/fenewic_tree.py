
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


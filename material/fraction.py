import math
class fraction: #分数
    def __init__(self,a=int,b=1):
        if b==0:
            raise ValueError("分母が0です")
        self.molecule=a
        self.denominator=b
        if a!=0:
            self.approx()
    def molecule(self):
        return self.molecule
    def denominator(self):
        return self.denominator
    def devide(self):
        f=self.molecule/self.denominator
        if f.is_integer():
            return int(f)
        else:
            return f
    def __add__(self,other):
        return fraction(self.molecule*other.denominator+other.molecule*self.denominator,self.denominator*other.denominator)
    def __sub__(self,other):
        return fraction(self.molecule*other.denominator-other.molecule*self.denominator,self.denominator*other.denominator)
    def __mul__(self,other):
        return fraction(self.molecule*other.molecule,self.denominator*other.denominator)
    def __truediv__(self,other):
        return fraction(self.molecule*other.denominator,self.denominator*other.molecule)
    def __str__(self):
        return str(self.molecule)+"/"+str(self.denominator)
    def is_irreducible(self):
        return True if self.molecule%self.denominator==0 else False
    def prime_factorize(self,n):
        a = []
        if n==1:
            return [1]
        while n % 2 == 0:
            a.append(2)
            n //= 2
        f = 3
        while f * f <= n:
            if n % f == 0:
                a.append(f)
                n //= f
            else:
                f += 2
        if n != 1:
            a.append(n)
        return a
    
    def approx(self):
        a,b=[],[]
        ar,br=1,1
        a=self.prime_factorize(self.molecule)
        b=self.prime_factorize(self.denominator)
        while True:
            if len(a)==0 or len(b)==0:
                ar*=math.prod(a)
                br*=math.prod(b)
                break
            if a[-1]==b[-1]:
                a.pop()
                b.pop()
            elif a[-1]>b[-1]:
                ar*=a.pop()
            elif a[-1]<b[-1]:
                br*=b.pop()

        self.molecule=ar
        self.denominator=br

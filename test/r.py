import os
import random

TEST_PATH=os.path.join("test",'tester.md')#テストファイルの出力先を入力

with open(TEST_PATH, 'w',encoding="utf-8") as f:
    print("# py",file=f)
    

def printf(*args,sep=" "):
    # print(*args)
    with open(TEST_PATH, 'a',encoding="utf-8") as f:
        print(*args,sep=sep,file=f)

N=2000
for i in range(N):
    printf("## "+str(i))
    printf("```")
    N=random.randint(2,10)
    Q=random.randint(1,20)
    printf(N,Q)
    for i in range(Q):
        q=random.randint(1,2)
        if q==1:
            pos=random.randint(1,N)
            x=random.randint(1,20)
            printf(q,pos,x)
        else:
            r=random.randint(2,N)
            l=random.randint(1,r-1)
            printf(q,l,r)
    printf("```")
    printf("```")
    printf("")
    printf("```")
    if (i+1)%500==0:
        print(i,"<<<<<<<<<<<<<")
    








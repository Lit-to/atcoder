import os
import random

TEST_PATH=os.path.join("test","monkey",'tester.md')#テストファイルの出力先を入力

with open(TEST_PATH, 'w',encoding="utf-8") as f:
    print("# py",file=f)
    

def printf(*args,sep=" "):
    # print(*args)
    with open(TEST_PATH, 'a',encoding="utf-8") as f:
        print(*args,sep=sep,file=f)

n=100
for i in range(n):
    printf("## "+str(i))
    printf("```")
    N=random.randint(1,20)
    A=[]
    printf(N)
    for i in range(N-1):
        A.append(random.randint(0,1))
    A.append(1)
    random.shuffle(A)
    printf(*A,sep="")
    printf("\n")
    printf("```")
    printf("```")
    printf("")
    printf("```")
    if (i+1)%500==0:
        print(i,"<<<<<<<<<<<<<")
    








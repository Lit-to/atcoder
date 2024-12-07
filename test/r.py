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
    H=random.randint(2,20)
    W=random.randint(2,20)
    D=random.randint(0,3)
    A=[]
    coma=["H",".","#",".","#",".","#"]

    printf(H,W,D)
    for i in range(H):
        wei=""
        for j in range(W):
            wei+=coma[random.randint(0,len(coma)-1)]
        printf(*wei,sep="")
    printf("```")
    printf("```")
    printf("")
    printf("```")
    if (i+1)%500==0:
        print(i,"<<<<<<<<<<<<<")
    








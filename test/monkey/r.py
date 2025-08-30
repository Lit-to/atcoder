import os
import random

TEST_PATH=os.path.join("test","monkey",'tester.md')#テストファイルの出力先を入力

with open(TEST_PATH, 'w',encoding="utf-8") as f:
    print("# py",file=f)
    

def printf(*args,sep=" "):
    # print(*args)
    with open(TEST_PATH, 'a',encoding="utf-8") as f:
        print(*args,sep=sep,file=f)

n=10000
for i in range(n):
    printf("## "+str(i))
    printf("```")
    N=random.randint(1,100)
    S = []
    for i in range(N):
        S.append("A")
    for i in range(N):
        S.append("B")
    random.shuffle(S)
    printf(N)
    printf(*S,sep="")
    printf("```")
    printf("```")
    printf("")
    printf("```")
    if (i+1)%500==0:
        print(i,"<<<<<<<<<<<<<")
    








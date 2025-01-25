import os
import random

TEST_PATH=os.path.join("test",'tester.md')#テストファイルの出力先を入力

with open(TEST_PATH, 'w',encoding="utf-8") as f:
    print("# py",file=f)
    

def printf(*args,sep=" "):
    # print(*args)
    with open(TEST_PATH, 'a',encoding="utf-8") as f:
        print(*args,sep=sep,file=f)

N=500
for i in range(N):
    printf("## "+str(i))
    printf("```")
    H=random.randint(1,15)
    W=random.randint(1,15)
    printf(H,W)
    C=[".","#","?"]
    for i in range(H):
        line=[]
        for j in range(W):
            line.append(C[random.randint(0,1)])
        printf("".join(line))
    printf("```")
    printf("```")
    printf("")
    printf("```")
    if (i+1)%500==0:
        print(i,"<<<<<<<<<<<<<")
    








import os
import random

TEST_PATH=os.path.join("test","monkey",'tester.md')#テストファイルの出力先を入力

with open(TEST_PATH, 'w',encoding="utf-8") as f:
    print("# py",file=f)
    

def printf(*args,sep=" "):
    # print(*args)
    with open(TEST_PATH, 'a',encoding="utf-8") as f:
        print(*args,sep=sep,file=f)

n=1
for i in range(n):
    printf("## "+str(i))
    printf("```")
    N=200
    M=500
    position=[]
    printf(N,M)
    while len(position)!=M:
        position.append((1,1))
    for j in position:
        printf(*j)
    printf("\n")
    printf("```")
    printf("```")
    printf("")
    printf("```")
    if (i+1)%500==0:
        print(i,"<<<<<<<<<<<<<")
    








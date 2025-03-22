import os
import random

TEST_PATH=os.path.join("test","monkey",'tester.md')#テストファイルの出力先を入力

with open(TEST_PATH, 'w',encoding="utf-8") as f:
    print("# py",file=f)
    

def printf(*args,sep=" "):
    # print(*args)
    with open(TEST_PATH, 'a',encoding="utf-8") as f:
        print(*args,sep=sep,file=f)

n=1000
for i in range(n):
    printf("## "+str(i))
    printf("```")
    N=random.randint(1,20)
    # printf(N)
    a=[]
    a.append("A")
    a.append("B")
    a.append("C")
    a.append("D")
    a.append("E")
    for i in range(N):
        a.append(random.choice(list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")))
    a.append("E")
    a.append("D")
    a.append("C")
    a.append("B")
    a.append("A")

    printf(*a,sep="")
    printf("```")
    printf("```")
    printf("")
    printf("```")
    if (i+1)%500==0:
        print(i,"<<<<<<<<<<<<<")
    








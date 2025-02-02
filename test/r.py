import os
import random

TEST_PATH=os.path.join("test",'tester.md')#テストファイルの出力先を入力

with open(TEST_PATH, 'w',encoding="utf-8") as f:
    print("# py",file=f)
    

def printf(*args,sep=" "):
    # print(*args)
    with open(TEST_PATH, 'a',encoding="utf-8") as f:
        print(*args,sep=sep,file=f)

n=500
for i in range(n):
    printf("## "+str(i))
    printf("```")
    N=random.randint(1,20)
    W=random.randint(1,N)
    position=set()
    while len(position)!=N:
        position.add((random.randint(1,W),random.randint(1,20)))
    printf(len(position),W)
    for i in position:
        printf(*i)
    Q=random.randint(1,10)
    printf(Q)
    for i in range(Q):
        printf(*(random.randint(1,30),random.randint(1,N)))
    print("\n")
    printf("```")
    printf("```")
    printf("")
    printf("```")
    if (i+1)%500==0:
        print(i,"<<<<<<<<<<<<<")
    








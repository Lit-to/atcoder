import os
import random

TEST_PATH=os.path.join("test",'tester.md')#テストファイルの出力先を入力

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
    N=5000
    printf(N)
    position=[]
    while len(position)!=N:
        position.append(random.randint(1,1000000000))
    printf(*position)
    position=[]
    while len(position)!=N:
        position.append(random.randint(1,1000000000))
    printf(*position)
    print("\n")
    printf("```")
    printf("```")
    printf("")
    printf("```")
    if (i+1)%500==0:
        print(i,"<<<<<<<<<<<<<")
    








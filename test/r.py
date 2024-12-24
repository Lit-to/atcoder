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
    N=random.randint(2,2*(10**5))
    # S=random.randint(1,500)
    printf(N)
    # A=[]
    # for i in range(N):
        # A.append(random.randint(1,100))
    # printf(*A)
    printf("```")
    printf("```")
    printf("")
    printf("```")
    if (i+1)%500==0:
        print(i,"<<<<<<<<<<<<<")
    








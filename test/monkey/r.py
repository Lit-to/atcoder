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
    a=[]
    
    for i in range(random.randint(2,20)):
        a.append(random.choice(["[","]","(",")","<",">"]))
    random.shuffle(a)
    printf(*a,sep="")
    
    printf("\n")
    printf("```")
    printf("```")
    printf("")
    printf("```")
    if (i+1)%500==0:
        print(i,"<<<<<<<<<<<<<")
    








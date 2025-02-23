#入力例から2ファイルチェックするもの
import time
import subprocess
import os
from collections import defaultdict
LOG_PATH=os.path.join("test","monkey","log.txt")#ログファイルのパスを書く
INPUT_PATH=os.path.join("test","monkey")#入力ファイルが入ったディレクトリのパス
# TARGET_PROGRAM=["pypy3",os.path.join("contest","ABC383","c.py")]#チェックするプログラムの実行コマンド
TARGET_PROGRAM=["python",os.path.join("test","monkey","correct.py"),"-Xfrozen_modules=off"]#チェックするプログラムの実行コマンド
CORRECT_PROGRAM=["python",os.path.join("contest","ABC394","d_recur.py"),"-Xfrozen_modules=off"]#正しいと思われるプログラムの実行コマンド

with open(os.path.join(LOG_PATH), 'w',encoding="utf-8") as f:
    print("",file=f)

def printf(*args):
    print(*args)
    with open(os.path.join(LOG_PATH), 'a',encoding="utf-8") as f:
        print(*args,file=f)

input_files = [file for file in os.listdir(INPUT_PATH) if file.endswith('.md')]

#入力ファイルのチェック
for input_file in input_files:
    printf(f"Comparing outputs for {input_file}")
    with open(os.path.join(INPUT_PATH, input_file), 'r') as f:
        if f.name[-3:]!=".md":
            printf("through file:",f.name)
            continue
        input_data = f.readlines()

mode=[]
input_type=input_data[0][2:-1]
iodata=[]
inp=defaultdict(lambda:[])

# 入力ファイルの確認
for i in input_data:
    if i=="\n" or i==" ":
        continue
    elif i=="# md\n" or i=="# py\n":
        continue
    elif 3<=len(i) and i[0:3]=="## ":
        assert mode==[],"cannot parse inputdata"
        inp=defaultdict(lambda:[])
        mode=["output","output","input","input"]
        inp["name"]=i[2:]
    elif i=="```\n":
        mode.pop()
        if mode==[]:
            iodata.append(inp.copy())
    else:
        inp[mode[-1]].append(i)

ngs=[]
c=0
# チェック開始
for i in iodata:
    start=time.perf_counter()
    is_tle=False
    is_wa=False
    status=-1
    try:
        note_output_1 = subprocess.check_output(TARGET_PROGRAM, input="".join(i["input"]), universal_newlines=True)
        finish=time.perf_counter()-start

        finish*=1000
        if 2000.00<finish:
            is_tle=True
        note_output_1=note_output_1.split("\n")
        note_output_2=[]
        if input_type=="py":
            note_output_2 = subprocess.check_output(CORRECT_PROGRAM, input="".join(i["input"]), universal_newlines=True)
            note_output_2=note_output_2.split("\n")
        else:
            note_output_2=i["output"].copy()

        for j in range(len(note_output_2)):
            if note_output_2[j].endswith("\n"):
                note_output_2[j]=note_output_2[j].rstrip()
            if note_output_1[j].endswith("\n"):
                note_output_1[j]=note_output_1[j].rstrip()
            if note_output_1[j]==note_output_2[j]:
                printf("[o]",note_output_1[j])
                pass
            else:
                printf("[x]","No.",j+1, "incorrect:",note_output_1[j],"correct:",note_output_2[j])
                is_wa=True
        status=is_tle*2+is_wa*3
    except:
        status=-1
    if status==-1:
        printf("[R E] No.",i["name"][:-1])
    if status==0:
        printf("[A C] No.",i["name"][:-1],">>>",finish,"ms")
    elif status==2:
        printf("[TLE] No.",i["name"][:-1],">>>",finish,"ms")
    elif status==3: 
        printf("[W A] No.",i["name"][:-1],">>>",finish,"ms")
        ngs.append(c)
    c+=1
# 結果のまとめ
# if input_type!="H":
#     with open(os.path.join("abc","tester","input",'ngs.txt'), 'w',encoding="utf-8") as f:
#         print("# py",file=f)
#     for i in range(len(ngs)):
#         with open(os.path.join("abc","tester","input",'ngs.txt'), 'a',encoding="utf-8") as f:
#             print("##",iodata[ngs[i]]["name"],file=f)
#             print("```",file=f)
#             for j in iodata[ngs[i]]["input"]:
#                 print(j[:-1],file=f,end="\n")
#             print("",file=f,end="")
#             print("```",file=f)
#             print("```",file=f)
#             print(*iodata[ngs[i]]["output"],file=f)
#             print("```",file=f)
    


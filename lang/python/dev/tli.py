import random
TEST_PATH="out"
with open(TEST_PATH, 'w',encoding="utf-8") as f:
    pass    

def printf(*args,sep=" "):
    # print(*args)
    with open(TEST_PATH, 'a',encoding="utf-8") as f:
        print(*args,sep=sep,file=f)
SQL = "INSERT INTO litter.posts (user_id, contents) VALUES ("
a = ["user_id","contents"]
printf("")
alphabet = list("abcdefghijklmnopqrstuvwxyz")
hiragana = list("あいうえおかきくけこさしすせそたちつてとなにぬねのはいふへほまみむめもやゆよわをん")
result = []
for i in range(5000):
    temp = [SQL]
    ids = []
    for j in range(random.randint(1,5)):
        ids.append(random.choice(alphabet))
    temp.append("'"+a[0]+"".join(ids)+"'")
    temp.append(",")
    contents = []
    for j in range(random.randint(1,50)):
        contents.append(random.choice(hiragana+alphabet))
    temp.append("'"+a[1]+"".join(contents)+"'")
    temp.append(");")
    result.append("".join(temp))

printf(*result,sep="\n")






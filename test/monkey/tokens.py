import random
TOKENS = {
    "N": lambda: str(random.randint(1, 2000)),
    "M": lambda: str(random.randint(1, 20000000)),
    "C": lambda: str(random.choice(["A","B"])),
    "A": lambda: str(random.randint(1, 100)),
}

if __name__=="__main__":
    for i in TOKENS.keys():
        print(i,TOKENS[i]())

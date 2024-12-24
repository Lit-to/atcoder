import itertools

for i in set(itertools.accumulate(list(input()))):
    print(int("".join(i))%8==0,"".join(i))




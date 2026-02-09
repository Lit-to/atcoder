import itertools
N = int(input())
A = list(map(int,input().split()))
S = int(input())
A.sort()
for j in range(1,N+1):
    for i in itertools.combinations(A,j):
        if sum(i)==S:
            print(*i)




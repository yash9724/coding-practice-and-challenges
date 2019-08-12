# https://www.codechef.com/AUG19B/problems/DSTAPLS
# Distribute Apples

try:
    T = int(input())
    while T!=0:
        T=T-1
        N,K = [int(x) for x in input().split()]
        if N%K**2 == 0:
            print("NO")
        else:
            print("YES")
except EOFError as e:
    print(end="")

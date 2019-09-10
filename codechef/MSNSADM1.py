# All test cases passed
# https://www.codechef.com/AUG19B/problems/MSNSADM1
# Football

try:
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = [int(x) for x in input().split()]
        B = [int(x) for x in input().split()] 
        C = []

        for i in range(N):
            c = 20*A[i] - 10*B[i]
            C.append(c if c>0 else 0)
        
        print(max(C))
except EOFError as e:
    print(end="")
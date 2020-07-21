# https://www.codechef.com/users/yash9724

try:
    T = int(input())
    while T:
        N,M,K,L,R = [int(x) for x in input().split()]
        C,P = [],[]
        for _ in range(N):
            c,p = map(int,input().split())
            C.append(c)
            P.append(p)
        
        # temp of each can after reaching home
        for i in range(N):
            if C[i]<K:
                if C[i]+M>=K:
                    C[i]=K
                else:
                    C[i]=C[i]+M
            
            elif C[i]>K:
                if C[i]-M<=K:
                    C[i]=K
                else:
                    C[i]=C[i]-M
            else:
                C[i]=K

        fav = []
        price = []
        for i in range(N):
            if C[i]>=L and C[i]<=R:
                fav.append(C[i])
                price.append(P[i])
        if len(price) == 0:
            print(-1)
        else:
            print(min(price))
        T = T-1

except EOFError:
    pass
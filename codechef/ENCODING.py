# https://www.codechef.com/AUG19B/problems/ENCODING
# Encoding

try:
    T = int(input())
    m = 10**9+7
    while(T):
        T = T-1
        Nl, L = [int(x) for x in input().split()]
        Nr, R = [int(x) for x in input().split()]

        t_sum = 0
        while(L<=R):
            sum = 0
            st = str(L)
            l = len(st)
            i=0
            while i<l:
                place = l-i-1
                sum = sum+int(st[i])*(10**place)
                j=i+1
                while j<l and st[j]==st[i]:
                    j=j+1
                i=j
            t_sum = t_sum + sum
            L = L+1
        print(t_sum%m)

except EOFError as e:
    print(end='')  
# All test cases passed
# https://www.codechef.com/AUG19B/problems/CHEFDIL
# Dilemma

try:
    T = int(input())
    for _ in range(T):
        S = [int(x) for x in list(input())]
        # '1': card is face-up
        # '0': card is face-down
        flag = 1
        i = 0
        while(i<len(S)):
            if(S[i] == 1):
                S[i] = -1
                if i!=0 and i!=len(S)-1:
                    if S[i+1] == 0:
                        S[i+1] = 1
                    elif S[i+1] == 1:
                        S[i+1] = 0
                    
                    if S[i-1] == 0:
                        S[i-1] = 1
                        i = i-1
            
                elif i == 0:
                    if S[i+1] == 0:
                        S[i+1] = 1
                    elif S[i+1] == 1:
                        S[i+1] = 0
                    i = i+1
                
                else:
                    if S[i-1] == 0:
                        S[i-1] = 1
                        i = i-1
            else:
                i = i+1
        
        for s in S:
            if s == 0:
                print("LOSE")
                flag = 0
                break
        if flag == 1:
            print("WIN")
        # print(S)

except EOFError as e:
    print(end="")



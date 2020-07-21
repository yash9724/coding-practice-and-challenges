// https://www.codechef.com/OCT19B/problems/MSV
// Chef and Maximum Star Value

#include<stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        int A[N],S[N];
        for(int i = 0 ; i < N ; i++){
            scanf("%d",&A[i]);
        }

        int max = -1;
        for(int i = 0 ; i < N ; i++){
            int count = 0;
            for(int j = 0 ; j < i ; j++){
                if(A[i]!=0){
                    if(A[j]%A[i] == 0)
                    count++;
                }
                
            }
            S[i] = count;
            if(S[i] > max)
                max = S[i];
        }

        printf("%d\n",max);

    }
    return 0;
}
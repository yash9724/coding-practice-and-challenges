// All test cases passed
// https://www.codechef.com/AUG19B/problems/MSNSADM1
// Football

#include<stdio.h>

int main(){
    int T, N;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        int A[N], B[N], C[N];
        for(int i=0;i<N;i++)
            scanf("%d",&A[i]);
        for(int i=0;i<N;i++)
            scanf("%d",&B[i]);
        for(int i=0;i<N;i++){
            int c = 20*A[i] - 10*B[i];
            C[i] = (c>=0 ? c : 0);
        }

        int max = C[0];
        for(int i=1;i<N;i++){
            if(C[i] > max)
                max = C[i];
        }
            
        printf("%d\n",max);
            
    }
    return 0;
}
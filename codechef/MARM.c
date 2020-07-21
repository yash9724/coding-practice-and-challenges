// https://www.codechef.com/OCT19B/problems/MARM#
// Array Modification

#include<stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        long long int K;
        scanf("%d%lld",&N,&K);
        int A[N];
        for(int i = 0 ; i < N ; i++)
            scanf("%d",&A[i]);
        int index_a,index_b;
        if(N != 0){
            int i = (K/(3*N))*3*N;
            if(N%2 == 1){
                A[N/2] = 0;
            }
            for(int j = i ; j < K ; j++){
                index_a = j%N;
                index_b = N-(j%N)-1;
                A[j%N] = A[index_a] ^ A[index_b];
            }

        }
        for(int i = 0 ; i < N ; i++){
            printf("%d ",A[i]);
        }
        printf("\n");
    }
    return 0;
}
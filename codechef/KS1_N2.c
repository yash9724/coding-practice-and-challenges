// Partially Solved - WA in last test case
// https://www.codechef.com/AUG19A/problems/KS1
// Guddu and his Mother
// O(N^2) solution

#include<stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        long int triplets = 0;
        scanf("%d",&N);
        int A[N+1];
        for(int i = 1 ; i <= N ; i++){
            scanf("%d",&A[i]);
        }

        // for(int i = 1 ; i <= N ; i++){
        //     printf("%d ",A[i]);
        // }
        // printf("\n");

        // finding prefix xor
        long int prefix_xor[N+1];
        prefix_xor[1] = A[1];
        for(int i = 2 ; i <= N ; i++)
            prefix_xor[i] =  A[i] ^ prefix_xor[i-1]; 

        // for(int i = 1 ; i <= N ; i++){
        //     printf("%d ",prefix_xor[i]);
        // }
        // printf("\n");
        for(int i = 1 ; i <= N ; i++){
            for(int j = i ; j <= N ; j++){
                long int xor;
                if(i != 1)
                    xor = prefix_xor[j] ^ prefix_xor[i-1];
                else 
                    xor = prefix_xor[j];
                
                if(xor == 0)
                    triplets += (j-i); 
            }
        }

        printf("%ld\n",triplets);  

    }
    return 0;
}
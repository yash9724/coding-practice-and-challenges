// Partially Solved - TLE in last subtask
// https://www.codechef.com/AUG19A/problems/KS1
// Guddu and his Mother
// O(N) solution

#include<stdio.h>
#include<time.h>

int main(){
    // clock_t start, end;
    // double cpu_time;
    int T;
    scanf("%d",&T);
    
    while(T--){
        // start = clock();
        int N;
        long long int triplets = 0;
        scanf("%d",&N);
        int A[N+1];
        for(int i = 1 ; i <= N ; i++){
            scanf("%d",&A[i]);
        }

        // finding prefix xor
        int prefix_xor[N+1];
        int max = 0;
        prefix_xor[1] = A[1];
        for(int i = 2 ; i <= N ; i++){
            prefix_xor[i] =  A[i] ^ prefix_xor[i-1]; 
            if(max < prefix_xor[i])
                max = prefix_xor[i];
        }
        
        int count[max+1], sub[max+1];
        for(int i = 0 ; i <= max ; i++){
            count[i] = 0;
            sub[i] = 0;
        }

        count[0] = 1;
        sub[0] = 1;

        for(int i = 1 ; i <= N ; i++){
            triplets = triplets + (long long int)(count[prefix_xor[i]] * i - sub[prefix_xor[i]]);
            count[prefix_xor[i]]++;
            sub[prefix_xor[i]] += (i+1);
        }

        printf("%lld\n",triplets);  

        // end = clock();
        // cpu_time = ((double)(end-start))/CLOCKS_PER_SEC;
        // printf("%lf",cpu_time);

    }
    return 0;
}
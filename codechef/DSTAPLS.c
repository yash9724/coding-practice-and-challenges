// All test cases passed
// https://www.codechef.com/AUG19B/problems/DSTAPLS
// Distribute Apples

#include<stdio.h>

int main(){
    int T;
    unsigned long long N,K,m;
    scanf("%d",&T);
    while(T--){
        scanf("%llu%llu",&N,&K);
        // printf("%llu\n%llu\n",N,K);
        if(K!=0){
        m = N/K;
        if(m%K == 0)
            printf("NO\n");
        else
            printf("YES\n");
        }      
    }
    return 0;
}
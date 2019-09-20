// https://www.codechef.com/FLMOCK01/submit/CHN15A
// Mutated Minions
// All test cases passed

#include<stdio.h>


int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N, K;
        scanf("%d%d",&N,&K);
        int CV[N];
        int count = 0;
        for(int i = 0 ; i < N ; i++){
            scanf("%d",&CV[i]);
            CV[i] += K;
            if(CV[i]%7 == 0)
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
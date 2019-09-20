// https://www.codechef.com/FLPAST01/problems/MAY19F1
// Lost Guy Radhu
// Status: All test cases passed.

#include<stdio.h>


int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N,Q;
        scanf("%d%d",&N,&Q);
        long long int scores[N];
        for(int i = 0 ; i<N; i++){
            scanf("%ld",&scores[i]);
        }
        
        long long int maxi[N];
        maxi[0] = scores[0];
        for(int i = 1 ; i < N ; i++){
            if(maxi[i-1] < scores[i])
                maxi[i] = scores[i];
            else
                maxi[i] = maxi[i-1];
        }

        while(Q--){
            int q;
            scanf("%d",&q);
            printf("%ld\n",maxi[q-1]);
        }

    }

    return 0;
}
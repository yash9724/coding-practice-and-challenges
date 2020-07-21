// https://www.codechef.com/OCT19B/problems/S10E
// Phone Prices

#include<stdio.h>
#include<climits>

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        int P[N+5];
        P[0]=P[1]=P[2]=P[3]=P[4] = INT_MAX;
        for(int i=5; i<N+5 ;i++){
            scanf("%d",&P[i]);
        }

        int count=0;
        for(int j=5; j<N+5 ; j++){
            int flag=0;
            for(int i=j-5 ; i<=j-1; i++){
                if(P[j] >= P[i]){
                    flag=1;
                    break;
                }
            }
            if(flag!=1)
                count++;
        }

        printf("%d\n",count);

    }
    return 0;
}

// partially solved - TLE
// https://www.codechef.com/LTIME75B/problems/COKE2
// Chef Drinks Coke Yet Again

#include<stdio.h>
#include<limits.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long int N,Q,K,L,R;
        scanf("%ld%ld%ld%ld%ld",&N,&Q,&K,&L,&R);
        long long int C[N+1],P[N+1];
        for(int i = 1 ; i<=N ; i++)
            scanf("%lld%lld",&C[i],&P[i]);
        long long int query[N+1];
        for(long int j = 1 ; j <= Q ; j++)
        {
            long long int min = INT_MAX;
            long int count = 0;
            for(long int i = 1 ; i <= N ; i++)
            {
                if(C[i] < K)
                {
                    if(C[i]+j >=K)
                        query[i] = K;
                    else
                        query[i] = C[i]+j;
                }
                else if(C[i] > K)
                {
                    if(C[i]-j <= K)
                        query[i] = K;
                    else
                        query[i] = C[i]-j;
                }
                else
                    query[i] = K;

                if(query[i]>=L && query[i]<=R && P[i] < min){
                    min = P[i];
                    count++;
                }
                    
            }
        
            if(count == 0)
                printf("%d ",-1);
            else
            {
                printf("%lld ",min); 
            }
        }
        printf("\n");
    }
    return 0;
}

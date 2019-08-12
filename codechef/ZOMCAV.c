// https://www.codechef.com/AUG19B/problems/ZOMCAV
// Zombies and the Caves

#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;

int cmpfunc(const void* a, const void* b){
    return (*(ll*)a - *(ll*)b);
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ll N;
        scanf("%lld",&N);
        ll C[N+1], H[N+1], R[N+1];
        for(ll i = 1; i <= N ; i++){
            R[i] = 0;
        }
        C[0]=H[0]=R[0]=-1;
        for(ll i = 1; i <= N ; i++){
            scanf("%lld",&C[i]);
        }

        for(ll i = 1; i <= N ; i++){
            scanf("%lld",&H[i]);
        }

        for(ll i = 1; i <= N ; i++){
            // for(ll j = i-C[i] ; j<=i+C[i] ; j++)
            //     if(j>=1 && j<=N)
            //         R[j] = R[j]+1;

            ll x = i-C[i];
            ll y = i+C[i];

            ll lb = x, ub = y;
            if(x<=1 && y<=1){
                lb = 1;
                ub = 1;
            }
            else if(x>=N && y>=N){
                lb = N;
                ub = N;
            }else if(x<=1 && y>=N){
                lb = 1;
                ub = N;
            }else if(x<=1 && y<=N){
                lb = 1;
                ub = y;
            }else if(x>=1 && y>=N){
                lb = x;
                ub = N;
            }

            R[lb] = R[lb] + 1;
            if(ub != N){
                R[ub+1] = R[ub+1] - 1;
            }

            // // if(lb<=ub && (lb>=1 && lb<=N) && (ub>=1 && ub<=N)){
            //     for(ll j=lb; j<=ub ; j++){
            //         R[j] = R[j]+1;
            //     // } 
            // }
        }

        // convert to prefix array

        for(int i = 2; i<=N ; i++){
            R[i] += R[i-1];     
        }

        qsort(R,N+1,sizeof(ll),cmpfunc);
        qsort(H,N+1,sizeof(ll),cmpfunc);

        // for(ll i= 1; i<=N ;i++)
        //     printf("%lld ",R[i]);

        // printf("\n");
        // for(ll i= 1; i<=N ;i++)
        //     printf("%lld ",H[i]);

        int flag = 1;
        for(ll i = 1; i <= N ; i++){
            if(H[i] != R[i]){
                flag = 0;
                break;
            }
        }

        if(flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
    
    }
    return 0;
}
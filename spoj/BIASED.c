#include<stdio.h>
#include<stdlib.h>

int comparator(const void* p1, const void* p2){
    long int l = *(long int*)p1;
    long int r = *(long int*)p2;
    return l-r;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        char teamName[100];
        int prefRank[N];
        for(int i = 0; i < N ; i++){
            scanf("%*s",teamName);
            scanf("%d",&prefRank[i]);
        }
        qsort(prefRank, N, sizeof(prefRank[0]), comparator);
        // for(int i = 0 ; i < N ; i++){
        //     printf("%d ", prefRank[i]);
        // }
        // printf("\n");
        // for(int i = 0 ; i < N ; i++){
        //     printf("%d ", teamName[i]);
        // }
        long long int badness = 0;
        for(int i = 0 ; i < N ; i++)
            badness += abs(prefRank[i] - (i+1));
            
        printf("%lld\n",badness);
    }
    return 0;
}
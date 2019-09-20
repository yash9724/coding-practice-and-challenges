// https://www.spoj.com/problems/BUSYMAN/
// I AM VERY BUSY

#include<stdio.h>
#include<stdlib.h>


int comparator(const void* p, const void* q){
    // get ending time at each address
    int l = *((const long int *)p+1);
    int r = *((const long int *)q+1);
    return l - r;
}

void printArr(long int arr[][2], int N){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < 2 ; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        long int tp[N][2];
        // int inc[N];
        // for(int i = 0 ; i < N ; i++){
        //     inc[i] = 0;
        // }
        for(int i = 0 ; i < N ; i++){
            scanf("%ld%ld",&tp[i][0],&tp[i][1]);
        }
        qsort((void*)tp, N, sizeof(tp[0]), comparator);
        // printArr(tp, N);
        // first activity will always be included.
        int count = 1;       
        int last = tp[0][1];
        // inc[0] = 1; 
    
        for(int i = 1; i<N ; i++){
            if(tp[i][0] >= last){
                
                count++;
                last = tp[i][1];
                // inc[i] = 1;
            }
        }
        

        // for(int i = 0 ; i < N ; i++)
        //     printf("%d ",inc[i]);
        // printf("\n");
        printf("%d\n",count);
    }
    return 0;
}
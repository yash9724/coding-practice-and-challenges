// https://www.codechef.com/problems/MARCHA1
// Paying Up

#include<stdio.h>

long int filterNotes(int* notes, int no){
    long int sum = 0;
    int i = 0;
    while(no>0){
        sum += (no&1)?notes[i]:0;
        i++;
        no = no>>1;
    }
    return sum;
}

void generateSubsets(int* notes, int N, int M){
    long int range = (1<<N)-1;
    long int sum;
    for(int i = 0; i <= range ; i++){
        sum = filterNotes(notes,i);
        if(sum == M){
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N,M;
        scanf("%d%d",&N,&M);
        int notes[N];
        for(int i = 0; i < N; i++){
            scanf("%d",&notes[i]);
        }
        
        generateSubsets(notes, N, M);
    }
    return 0;
}
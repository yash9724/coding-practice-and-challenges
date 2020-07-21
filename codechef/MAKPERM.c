// https://www.codechef.com/COOK98B/status/MAKPERM,yash9724

#include<stdio.h>
#include<string.h>

int main(){
  int T,N;
  scanf("%d",&T);

  while(T--){
    scanf("%d",&N);
    int A[N+1];
    int freq[N+1],moves = 0;
    memset(freq,0, sizeof(int) * N+1);
    for(int i =1 ; i<N+1 ;i++){
      scanf("%d",&A[i]);
      if(A[i] <= N)
          freq[A[i]]++;
    }

    for(int i = 1 ; i <=N ; i++){
      if(A[i] > N)
        moves++;
      else if(freq[A[i]] > 1){
        freq[A[i]]--;
        moves++;
      }  
    }

    printf("%d\n",moves);
  }
  return 0;
}
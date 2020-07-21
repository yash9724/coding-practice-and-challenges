// https://www.codechef.com/COOK98B/status/ATM2,yash9724
// problem : ATM Machine
// status: all test cases passed
 
#include<stdio.h>
#include<string.h>

int main(){

  int T,N,K;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&N,&K);
    int req;
    char res[N+1];

    for(int i =0 ; i < N ; i++){
      scanf("%d",&req);
      if(req <= K){
         K -= req;
         res[i]='1';
      }else{
        res[i] = '0';
      }
       
    }

    res[N] = '\0';
    printf("%s",res);
    printf("\n");

  }


  return 0;
}
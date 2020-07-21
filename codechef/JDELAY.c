// https://www.codechef.com/LTIME64B/status/JDELAY,yash9724

#include<stdio.h>

int main(){
  int T,N,S,J;
  scanf("%d",&T);
  while(T--){
    int count = 0;
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
      scanf("%d%d",&S,&J);
      if(J-S > 5)
        count++;
    }
    printf("%d\n",count);
  }
  return 0;
}
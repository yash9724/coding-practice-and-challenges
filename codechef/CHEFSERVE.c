// https://www.codechef.com/OCT18B/status/CHSERVE,yash9724
// problem: Chef and Serves
// status: all test cases passed

#include <stdio.h>

int main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  int T;
  long long int P1,P2,K,sum,res;
  scanf("%d",&T);
  while(T--){
    scanf("%lld%lld%lld",&P1,&P2,&K);
    sum = P1+P2; 
    res = sum/K + 1;
    if(res & 1)
      printf("\"CHEF\"\n");
    else
      printf("\"COOK\"\n");  
    
}
  return 0;
}
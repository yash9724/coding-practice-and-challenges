// problem : ATM
// https://www.codechef.com/viewsolution/20186542
// status: All test cases passed

#include <stdio.h>

int main(){
  int withdraw;
  float initial_bal,remaining_amt;
  scanf("%d",&withdraw);
  scanf("%f",&initial_bal);
  if(withdraw % 5 == 0  &&  initial_bal >= withdraw + 0.5){
    remaining_amt = initial_bal - withdraw - 0.50;
    printf("%.2f",remaining_amt);
    return 0;
  }

  printf("%.2f",initial_bal);
  return 0;
}
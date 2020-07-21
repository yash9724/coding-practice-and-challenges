// problem: The Alien
// https://www.codechef.com/viewsolution/20292551
// status: All test cases passed

#include <stdio.h>

int main(){
  int x,p,y,q,flag = -1,res = 0;
  long long int a[100],b[100];
  scanf("%d%d",&x,&p);
  scanf("%d%d",&y,&q);

  //find first 100 terms in both series

  for(int i = 0 ; i < 100; i++){
    a[i] = p + x*i;
    b[i] = q + y*i;
  }

  for(int i = 0 ; i < 100; i++){
    for(int j = 0 ; j < 100; j++){
      if(a[i] == b[j]){
           res = a[i];
           flag++;
           break;
      }
    }
    if(flag == 0)
      break;
  }

  if(!flag)
    printf("%d",res);
  else
    printf("%d",flag);  
    
  
return 0;
}


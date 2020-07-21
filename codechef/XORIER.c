// problem: War of XORs
// https://www.codechef.com/viewsolution/20288402
// status: all test cases passed

#include <stdio.h>


int main(){
  int testCases;
  scanf("%d",&testCases);

  while(testCases-- > 0){
    int N,freq_arr[1100001] = {0};
    long long int count = 0,even = 0,odd = 0,;
    scanf("%d",&N);
    int a[N];
    for(int i = 0 ; i < N ; i++){
      scanf("%d",&a[i]);
      if(a[i]&1){
          odd++;
      }
      else{
          even++;  
      } 
      freq_arr[a[i]];
    }

    for(int i = 0 ; i < N ; i++){
      if(a[i]&1)
        count += odd;
      else
        count += even;
      count -= freq_arr[a[i]^2];
      count -= freq_arr[a[i]];     
    }

     printf("%lld",count/2);
  }

 return 0;
}
// Problem: GIT01 Contest: Practice(school) 
// https://www.codechef.com/viewsolution/19964310
// status: all test cases passed


#include<stdio.h>

int main(){
	int T,N,M;
	char pattern[101][101];
	scanf("%d",&T);
	while(T--){
      scanf("%d%d",&N,&M);
      for(int i = 0 ; i < N ; i++)
      	  scanf("%s",pattern[i]);

      int min_green_cost = 0,min_red_cost = 0;	
      

      for(int i = 0 ; i < N ; i++){
      	for(int j = 0 ; j < M ; j++){
			/*When starting color is RED*/
            if((i+j)%2 == 0 && pattern[i][j] == 'G')
            	min_red_cost = min_red_cost + 3;
            else if((i+j)%2 != 0 && pattern[i][j] == 'R')
            	min_red_cost = min_red_cost + 5;
			
			/*When starting color is GREEN*/	
			else if((i+j)%2 == 0 && pattern[i][j] == 'R')
				min_green_cost = min_green_cost + 5;
			else if((i+j)%2 != 0 && pattern[i][j] == 'G')
				min_green_cost = min_green_cost + 3;

      	}
      }

      printf("%d\n",min_green_cost > min_red_cost ? min_red_cost : min_green_cost );
      
   }


	return 0;
}
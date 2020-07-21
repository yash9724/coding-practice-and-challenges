//TRISQ
// https://www.codechef.com/users/yash9724
// status: all test cases passed

#include<stdio.h>

int main()
{
	int T,B,i,sections_of_height;
	long count;
    scanf("%d",&T);
	while(T>0)
	{   
		scanf("%d",&B);
		sections_of_height = B/2;
		count = 0;
		for(i = 0 ; i < sections_of_height && B > 0 ; i++)
  		{
  			B=B-2;
  			count=count+B/2;
  		}
  		printf("%li\n",count);
  		T--;
    }
	return 0;
}
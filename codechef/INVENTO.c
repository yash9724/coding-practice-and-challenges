// problem: INVENTO
// https://www.codechef.com/viewsolution/20386405
// status: solved

#include<stdio.h>
#include<math.h>
int main()
{
	int T,i=1;
	long long int N,num=1;
	scanf("%d",&T);
	while(T>0)
	{
		scanf("%lld",&N);
		while(num<=N)
		{
			num=pow(2,i);
			i++;
		}
		printf("%d\n",i-1);
		i=1;
		num=1;
		T--;
	}
	return 0;
}
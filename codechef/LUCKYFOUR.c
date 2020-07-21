//Lucky Four ---> LUCK FOUR

#include<stdio.h>

int main()
{
	int T,N,R;
	unsigned short count;
	scanf("%d",&T);
	while(T>0)
	{
		scanf("%d",&N);
		count = 0;
		while(N>0)
		{
			R=N%10;
			if(R==4)
				count++;
			N=N/10;
		}
		printf("%hu\n",count);
		T--;
	}
	return 0;
}  
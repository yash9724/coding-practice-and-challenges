#include <stdio.h>
#include <stdbool.h>

void main()
{
	int n, test_cases;
	scanf("%d",&test_cases);

	for(int k = 1; k<= test_cases; k++)
	{
		scanf("%d",&n);

		bool prime[n+1];

		for(int i = 2; i<=n ;i++)
			prime[i] = true;

		prime[0] = false;
		prime[1] = false;


		for(int p = 2 ; p * p <= n ; p++)
		{
			if(prime[p] == true)
			{
				for( int i = p * 2 ; i<=n ; i = i+p)
					prime[i] = false;
			}
		}
		int counter = 0;

		for( int p =2 ; p<= n ; p++)
			{
				if(prime[p] == true)

				{  counter++; 
					printf("%d ",p);
				}
			}	

		printf("\n\n%d",counter);	

	}
}
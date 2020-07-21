//Sieve of eratosthenes using loop

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void main()
{
	int testCases, n;

	printf("Enter number of testCases: ");
	scanf("%d",&testCases);

	for( int k=1 ; k<=testCases ; k++ )
	{
		printf("\nTest Case %d: " , k);
		scanf("%d",&n);

		bool sieve[n+1];

		for( int i=2; i<=n ; i++)
			sieve[i] = true;

		sieve[0] = false;
		sieve[1] = false;

		for( int i=2 ; i<=sqrt(n) ; i++)
		{
			if(sieve[i] == true)
			{
				for( int j=i*i ; j<=n ; j=j+i)
				sieve[j] = false; 
			}
		}


		int counter = 0 ; 

		for( int i=0 ; i<=n ; i++ )
		{
			if(sieve[i] == true)
			{
				counter++;
				printf("%d ",i);
			}
		}

		printf("\n\n%d", counter);
	}

	return;
} 
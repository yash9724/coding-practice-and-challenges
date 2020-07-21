// optimized version of sieve of eratosthenes

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void sieveOfEratosthenes(int n);

void main()
{
   int testCases, n;

   printf("Enter number of testCases: ");
   scanf("%d",&testCases);

   for(int i =1 ; i<= testCases ; i++)
   	{
   		printf("Test case %d:", i);
   		scanf("%d",&n);
   		sieveOfEratosthenes(n);
   		printf("\n\n");

   	}	

   	return;
}

void sieveOfEratosthenes( int n )
{
	bool sieve[n+1];

	for(int i = 2 ; i<=n ; i++)
		sieve[i] = true;                                                  // 1 --> isPrime
																	   // 0 --> isNotPrime
	sieve[0] = false;
	sieve[1] = false;

     for( int i = 2 ; i<= sqrt(n) ; i++)
     {
     	if( sieve[i] == true)
     	{
     		for( int j = i * i ; j<=n ; j = j+i)
     			sieve[j] = false;
     	}
     }

     int counter = 0;

     for(int i = 0 ; i<=n ; i++)
     {
     	if(sieve[i] == true)
 		{   
 		    counter++;   
     		printf("%d ",i);
     	}	
     }

     printf("\n\n%d",counter);
}

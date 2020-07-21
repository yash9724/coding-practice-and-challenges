//program to reverse two numbers , add them and then finally reverse their sum


#include <stdio.h>
#include <math.h>

int rev( int num );
int main()
{
	int a , b , N;

	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d",&a,&b);
		a = rev(a);
		b = rev(b);

		a = rev( a + b);
		printf("%d\n",a);


	}

	return 0;
}


int rev( int num )
{
	int rem , arr[100], count = 0;
	if(num == 0)
	{
		arr[count] = 0;
		count++;
	}

	else
	{

		while( num != 0 )
			{
				arr[count++] = num % 10 ;
				num = num / 10;
			}
	}

	num = 0;
	
	for( int i =0 ; i< count ; i++ )
	{
		num = num + arr[i] * pow(10, count - i - 1);
	}	

	return num;	
}
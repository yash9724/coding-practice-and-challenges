#include <stdio.h>

void main()
{
	int input;
	while(1)
	{
		scanf("%d",&input);
		if( input != 42)
			printf("%d\n",input);
		else 
			break;
	}

	return ;
}
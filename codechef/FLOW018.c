// https://www.codechef.com/viewsolution/19933989
//  problem: small factorial
// status: all test cases passed

#include<stdio.h>

int main()
{
	int test_cases,num;
	unsigned long long int factorial;
	scanf("%d",&test_cases);
	while(test_cases > 0){
		scanf("%d",&num);
        factorial = 1;
		while(num > 0){
			factorial = factorial * num;
			num--;
		}

		printf("%llu\n",factorial);
		test_cases--;
	}

	return 0;
}
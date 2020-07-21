// Total Expenses------------------------------Problem Code: FLOW009
// https://www.codechef.com/status/FLOW009,yash9724
// status: All test cases passed 

#include<stdio.h>

int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases > 0)
	{
	    long int quantity,price;
		scanf("%lu%lu",&quantity,&price);
		long double expenses;
		long double cost = quantity * price;
	    if(quantity > 1000){
			expenses = (90.0 * cost)/100;
		}
		else{
			expenses = cost;
		}
		printf("%0.6Lf\n",expenses);
		test_cases--;

	}
	return 0;
}
// https://www.codechef.com/viewsolution/19931561
// problem: Bear and Candies 123
// status: all test cases passed


#include<stdio.h>

int limak_turns(int max_limak_candies);
int bob_turns(int max_bob_candies);
int main()
{
	int test_cases,max_limak_candies,max_bob_candies;
	scanf("%d",&test_cases);
	while(test_cases > 0){
		int limak_count,bob_count;
        scanf("%d%d",&max_limak_candies,&max_bob_candies);
        limak_count = limak_turns(max_limak_candies);
        bob_count = bob_turns(max_bob_candies);
        if(limak_count > bob_count)
        	printf("%s\n","Limak");
        else
        	printf("%s\n","Bob");
        test_cases--;
	}
	return 0;
}

int limak_turns(int max_limak_candies){
	int count = 0,total = 0,next = 1;
    while(total < max_limak_candies){
    	total = total + next;
    	if(total <= max_limak_candies)
    		count++;
    	next = next + 2;
    }
    return count;
}

int bob_turns(int max_bob_candies){
	int count = 0,total = 0,next = 2;
	while(total < max_bob_candies){
		total = total + next;
		if(total <= max_bob_candies)
			count++;
		next = next + 2;
	}
	return count;

}
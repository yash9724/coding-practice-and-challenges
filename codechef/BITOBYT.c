// https://www.codechef.com/viewsolution/20583949
//bitobyte.c
#include <stdio.h>
 
int main(void) {
	int T;
 
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
 
	scanf("%d",&T);
	while(T--){
		int N;
        long long int bit = 1, nibble=0, byte=0;
		scanf("%d",&N);
		int change = 1 , x = N-1;
		while(x>0 && change!=0){
			change = 0;
			if(x>=2 && bit!=0){
				nibble = nibble+bit;
				bit=0;
				x=x-2;
				change++;
			}
			if(x>=8 && nibble!=0){
				byte=byte+nibble;
				nibble=0;
				x=x-8;
				change++;
			}
			if(x>=16 && byte!=0){
				bit=bit+2*byte;
				byte=0;
				x=x-16;
				change++;
			}
		}
		printf("%lld %lld %lld\n",bit,nibble,byte);
 }
	return 0;
}
 

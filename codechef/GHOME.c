// All test cases passed
// https://www.codechef.com/COHA2019/problems/GHOME
// Gaithonde owns a new home


#include<stdio.h>
#include<math.h>

int main(){
    long int m,n;
    scanf("%ld%ld",&m,&n);
    unsigned long long int res = m*n;
    printf("%llu\n",(unsigned long long int)ceil(res/2.0));
    return 0;
}
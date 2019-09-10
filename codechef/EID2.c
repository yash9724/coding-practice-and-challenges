// All test cases passed
// https://www.codechef.com/LTIME75B/problems/EID2
// Eidi Gift

#include<stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int val[6];
        for(int i = 0 ; i < 6 ; i++){
            scanf("%d",&val[i]);
        }

        if((val[0] > val[1] && val[3] > val[4]) ||
           (val[0] < val[1] && val[3] < val[4]) ||
           (val[0] == val[1] && val[3] == val[4]))
        {
            if((val[1] > val[2] && val[4] > val[5]) ||
               (val[1] < val[2] && val[4] < val[5]) ||
               (val[1] == val[2] && val[4] == val[5]))
            {
                if((val[0] > val[2] && val[3] > val[5]) ||
                  (val[0] < val[2] && val[3] < val[5]) ||
                  (val[0] == val[2] && val[3] == val[5]))
                  {
                      printf("FAIR\n");
                  }
                  else
                  {
                      printf("NOT FAIR\n");
                  }
            }
            else
            {
                printf("NOT FAIR\n");
            }
        }
        else
        {
            printf("NOT FAIR\n");
        }
    }
    return 0;
}
// https://www.codechef.com/FLMOCK01/problems/LAPIN
// LAPIN
// Status --> WRONG ANSWER


#include<stdio.h>
#include<string.h>
#include<math.h>


int main(){
    
    int T;
    scanf("%d",&T);
    getchar();
    while(T--){
        char S[1001];
        fgets(S,1001,stdin);
        int len = strlen(S)-1;
        int flag = 0;
        int firstHalf[26], secondHalf[26];
        for(int i = 0 ; i < 26 ; i++)
        {
            firstHalf[i] = 0;
            secondHalf[i] = 0;
        }



        int j = len-1;
        
        for(int i = 0 ; i < j ; i++){
            
            firstHalf[S[i]-'a']++;
            secondHalf[S[j]-'a']++;
            j--;
        }
       
        for(int i = 0 ; i < 26 ; i++){
            if(firstHalf[i] != secondHalf[i]){
                flag = 1;
                break;
            }
        }

        // print frequency in first half and second half
        // for(int i = 0 ; i < 26 ; i++)
        //     printf("%d ",firstHalf[i]);
        // printf("\n");
        // for(int i = 0 ; i < 26 ; i++)
        //     printf("%d ",secondHalf[i]);
        if(len < 2 )
            flag = 1;
        
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}

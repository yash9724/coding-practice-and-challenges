// Chef and Time Machine 
// https://www.codechef.com/problems/CHEFTMA


#include<bits/stdc++.h>

using namespace std;

int main(){
    int T, N, K, M;
    cin >> T;
    while(T--){
        cin >> N >> K >> M;
        int A[N], B[N], C[K+M];

        for(int i = 0 ; i < N ; i++){
            cin >> A[i];
        }

        
        for(int i = 0 ; i < N ; i++){
            cin >> B[i];
        }
    
        for(int i = 0 ; i < K+M ; i++){
            cin >> C[i];
        }

       
        int UCT[N];
        for(int i = 0 ; i < N ; i++){
            UCT[i] = A[i] - B[i];
        }

        sort(UCT, UCT+N, greater<int>());
        sort(C, C+K+M , greater<int>());

        int ans = 0;
        int i = 0, j = 0;
        while(j < K+M ){
            if(UCT[i] - C[j] >=  0){
                UCT[i] = UCT[i] - C[j];
                i++;
                j++;
            }else{
                j++;
            }
        }

        for(int i = 0 ; i < N ; i++){
            ans += UCT[i];
        }
        cout << ans << endl;
    }

    return 0;
}
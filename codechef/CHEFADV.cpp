// https://www.codechef.com/problems/CHEFADV
// Chef and Adventures |  Problem Code: CHEFADV

#include<iostream>

using namespace std;

int main(){

    int T;
    cin >> T;
    while(T--){
        long long N,M,X,Y;
        cin >> N >> M >> X >> Y;


        long long k, p;
        k = N-1;
        p = M-1;
        
        if((k%X == 0 &&  p%Y == 0))
            cout << "Chefirnemo"<< endl;
        else if ( (k-1)%X == 0 && (p-1)%Y == 0 && min(k,p) > 0) 
            cout << "Chefirnemo"<< endl;
        else 
            cout << "Pofik" << endl; 
    
        
    } 
    return 0;
}
// https://hack.codingblocks.com/app/practice/2/p/463
// Unique Numbers II

#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    int A[N];
    for(int i = 0 ; i < N ; i++)
        cin >> A[i];
    int c_xor = 0;
    for(int i = 0 ; i < N ; i++)
        c_xor ^= A[i];

    int setbit = 0;
    int flag = 0;
    while(c_xor > 0){
        if(c_xor&1){
            flag = 1;
            break;
        }
        c_xor = 1>>c_xor;
        setbit++;
    } 
    int first = 0;
    int no = 1<<setbit;
    if(flag){
        for(int i = 0 ; i < N ; i++){
            if(A[i]&no){
                first = first ^ A[i];
            }
        }
    }
    int second = first^c_xor;
    cout<<first<<" "<<second<<endl;
    return 0;
}
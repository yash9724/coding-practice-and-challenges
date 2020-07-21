// https://www.hackerrank.com/challenges/qheap1/problem
// status:solved

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int &i, int &j){
  int temp = i;
  i = j;
  j = temp;
}

void min_heapify(vector<long long> &A, int i){
//   cout << "in min_heapify"<<endl;
  int smallest;
  int left = 2*i + 1;
  int right = 2*i + 2;

  if(left < A.size() && A[left] < A[i])
      smallest = left;
  else
      smallest = i;
  if(right < A.size() && A[right] < A[smallest])
      smallest = right;

  if(smallest != i){
    swap(A[smallest], A[i]);
    min_heapify(A, smallest);
  }
} 

void build_heap(vector<long long> &A){
    // cout << "in build heap"<<endl;
    int last_non_leaf = (A.size()-2)/2;
    for(int i = last_non_leaf ; i >= 0 ; i--){
        min_heapify(A, i);
    }
}

void insert(vector<long long> &A, long long v){
    // cout << "in insert"<<endl;
    A.push_back(v);
    int index = A.size()-1;
    int parent = (index-1)/2;
    while(index > 0 && A[parent] > A[index]){
        swap(A[parent], A[index]);
        index = parent;
        parent = (index-1)/2; 
    }
    // cout<<"Inserted "<<v<<endl;
}

void del(vector<long long> &A, long long v){
    // cout << "in del"<<endl;
    vector<long long >::iterator it;
    int index;
    it = find(A.begin(), A.end(), v);
    if(it != A.end()){
        A.erase(it);
        build_heap(A);
    }
    // cout<<"deleted "<<v<<endl;
}

long long min(vector<long long> &A){
    return A[0];
}

int main() {
    int Q;
    cin>>Q;
    vector<long long> min_heap;
    int op, value;
    while(Q--){
        cin>>op;
        switch(op){
            case 1:
                cin>>value;
                insert(min_heap, value);
                break;
            case 2: 
                cin>>value;
                del(min_heap, value);
                break;
            case 3: cout<<min(min_heap)<<endl;
        }
    }
    return 0;
}

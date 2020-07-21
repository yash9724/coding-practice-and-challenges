// Problem:
// We have an array a[0...n-1]. We should be able to efficiently 
// find the minimum value from index qs(query start) to qe(query end)
// where 0 <= qs <= qe <= n-1.
// Also write code for efficient updates on an element
// or a range of element

#include<iostream>
#include<climits>
using namespace std;

void buildTree(int* a, int s, int e, int* tree, int index){
    // base case
    if(s == e){
        tree[index] = a[s];
        return;
    }

    // recursive case
    int mid = (s+e)/2;
    buildTree(a, s, mid, tree, 2*index);
    buildTree(a, mid+1, e, tree, 2*index+1);
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
}

int query(int* tree, int ss, int se, int qs, int qe, int index){
    // complete overlap
    if(ss>=qs && se<=qe)
        return tree[index];

    // no overlap
    if(ss>qe || se<qs)
        return INT_MAX;
    
    // partial overlap
    int mid = (ss+se)/2;
    int leftMin = query(tree, ss, mid, qs, qe, 2*index);
    int rightMin = query(tree, mid+1, se, qs, qe, 2*index+1);
    return min(leftMin, rightMin);
}

// updating single index
void updateIndex(int* tree, int ss, int se,  int i, int incr, int index){
    // out of bounds range
    if(i>se || i<ss){
        return;
    }

    // leaf node
    if(ss == se){
        tree[index] = tree[index] + incr;
        return;
    }

    // partial overlap - call left and right child
    int mid = (ss+se)/2;
    updateIndex(tree, ss, mid, i, incr, 2*index);
    updateIndex(tree, mid+1, se, i, incr, 2*index+1);
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
}

// updating range of indices
int updateRange(int* tree, int ss, int se, int l, int r, int incr, int index){
    // out of bounds
    if(l > se || r < ss)
        return;

    // leaf node
    if(ss == se){
        tree[index] += incr;
        return;
    }

    // partial overlap - call left and right child
    int mid = (ss+se)/2;
    updateRange(tree, ss, mid, l, r, incr, 2*index);
    updateRange(tree, mid+1, se, l, r, 2*indx+1);
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
}


int main(){
    int n;
    // cin>>n;
    int a[] = {1, 3, 2, -5, 6, 4};
    n = sizeof(a)/sizeof(int);
    // for(int i = 0 ; i < n ; i++)
    //     cin>>a[i];
    
    int* tree = new int[4*n+1];
    buildTree(a, 0, n-1, tree, 1);

    // print tree
    for(int i = 1; i<=4*n; i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;

    // query
    int l=2, r=5;
    // cin>>l>>r;
    cout<<query(tree, 0, n-1, l, r, 1);

    // update index
    updateIndex(tree, 0, n-1, 4, -3, 1);

    // print tree
    for(int i = 1; i<=4*n; i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    return 0;
}
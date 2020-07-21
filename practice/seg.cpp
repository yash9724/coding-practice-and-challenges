#include<iostream>
#include<climits>

using namespace std;

void buildTree(int* A, int* tree, int L, int R, int index){
    if(L==R){
        tree[index] = A[L];
        return;
    }

    int mid = (L+R)/2;
    buildTree(A, tree, L, mid, 2*index);
    buildTree(A, tree, mid+1, R, 2*index+1);
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
}

int query(int* tree, int qs, int qe, int ss, int se, int index){
    // complete overlap
    if(ss >= qs && se <= qe){
        return tree[index];
    }

    // No Overlap -- Base Case
    if(qe < ss || qs > se ){
        return INT_MAX;
    }

    // Partial Overlap
    int mid = (ss+se)/2;
    int leftAns = query(tree, qs, qe, ss, mid, 2*index);
    int rightAns = query(tree, qs, qe, mid+1, se, 2*index+1);
    return min(leftAns, rightAns);
}

void updateNode(int* tree, int ss, int se, int incr, int i, int index){
    // Out Of Bounds
    if(i < ss || i > se)
        return;
    
    // Leaf Node
    if(ss == se){
        tree[index] += incr;
        return;
    }

    // Partial overlap
    int mid = (ss+se)/2;
    updateNode(tree, ss, mid, incr, i, 2*index);
    updateNode(tree, mid+1, se, incr, i, 2*index+1);
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
}

void updateRange(int* tree, int ss, int se, int incr, int l, int r, int index){
    // Out of Bounds
    if(l > se || r < ss)
        return;
    
    // Leaf Node
    if(ss == se){
        tree[index] += incr;
        return;
    }

    // Partial Overlap
    int mid = (ss+se)/2;
    updateRange(tree, ss, mid, incr, l, r, 2*index);
    updateRange(tree, mid+1, r, incr, l, r,2*index+1);
    tree[index] = min(tree[2*index], tree[index+1]);
    return;
}

int main(){
    int A[] = {1,3,2,-5,6,4};
    int N = sizeof(A)/sizeof(A[0]);
    int* tree = new int(4*N+1);
    buildTree(A, tree, 0, N-1, 1);
    for(int i = 1; i <= 13; i++)
        cout<<tree[i]<<" ";
    cout<<endl;

    // query
    cout<<query(tree, 0, N-1, 2,4,1)<<endl;

    // update node
    updateNode(tree, 0, N-1, 1, 3, 1);

    for(int i = 1; i <= 13; i++)
        cout<<tree[i]<<" ";
    cout<<endl;

    // update range of nodes
    updateRange(tree, 0, N-1, 8,2,5, 1);

    for(int i = 1; i <= 13; i++)
        cout<<tree[i]<<" ";
    cout<<endl;

}
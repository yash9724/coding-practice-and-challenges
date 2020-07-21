// Swap Nodes[Algo]
// https://www.hackerrank.com/challenges/swap-nodes-algo/problem
// status: solved

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
*/

struct node{
    int data;
    struct node* left;
    struct node* right;
    int depth;
};

struct node* getNode(int data, int depth){
    struct node* temp = new node[1];
    temp->data = data;
    temp->left=NULL;
    temp->right=NULL;
    temp->depth = depth;
    
    return temp;
}

struct node* constructTree(vector<vector<int>> indexes, struct node* root, int arrSize){
    root = getNode(1,1);
    struct node* temp = root; 
    queue<struct node*> q;
    int N = 0;
    q.push(root);
    
    while(N < arrSize){
        temp = q.front();
        q.pop();

        temp->left = indexes[N][0] == -1 ? NULL : getNode(indexes[N][0], temp->depth+1);
        temp->right = indexes[N][1] == -1 ? NULL : getNode(indexes[N][1], temp->depth+1);

        if(temp->left && temp->left->data != -1)
            q.push(temp->left);
        if(temp->right && temp->right->data != -1)
            q.push(temp->right);

        N++;
    }

    return root;
}

void inorder(struct node* root, vector<vector<int>> &result, int queryNo){
    if(root){
        inorder(root->left, result, queryNo);
        result[queryNo].push_back(root->data);
        inorder(root->right, result, queryNo);
    }
}

void swap(struct node* curr){
    struct node* temp = curr->left;
    curr->left = curr->right;
    curr->right = temp;
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {

    struct node *root = NULL;
    root = constructTree(indexes, root, indexes.size());
    

    int noOfQueries = queries.size();
    vector<vector<int>> result(noOfQueries);
    int i = 0;
    while(i < noOfQueries){
        int k = queries[i];
        queue<struct node*> q;
        q.push(root);
        while(!q.empty()){
            struct node* temp = q.front();
            q.pop();
            if(temp->depth%k == 0)
                swap(temp);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        inorder(root, result, i);
        
        i++;
    }

    // for(int i = 0 ; i < result.size(); i++){
    //     for(int j = 0 ; j < result[i].size() ; j++)
    //         cout<<result[i][j]<<" ";
    //     cout<<endl;
    // }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

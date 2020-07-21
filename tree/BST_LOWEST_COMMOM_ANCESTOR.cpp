// BST: Lowest common ancestor
// https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem
// status: solved




/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    Node *lca(Node *root, int v1,int v2) {
        if(!root)
            return NULL;
        
        vector<Node*> arr1;
        vector<Node*> arr2;

        Node *ptr = root;

        while(ptr != NULL && ptr->data != v1){
            arr1.push_back(ptr);
            if(v1<ptr->data)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        arr1.push_back(ptr);

        // for(int i = 0 ; i < (int)arr1.size() ; i++)
        //     cout << arr1[i]->data << ",";
        // cout << endl;

        ptr = root;
        while(ptr != NULL && ptr->data != v2){
            arr2.push_back(ptr);
            if(v2<ptr->data)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        arr2.push_back(ptr);
        // for(int i = 0 ; i < (int)arr1.size() ; i++)
        //     cout << arr2[i]->data << ",";
        // cout << endl;
        vector<Node*> arr3;
    
        for(int i = 0 ; i < arr1.size() && i < arr2.size() ; i++){
            if(arr1[i]->data == arr2[i]->data)
                arr3.push_back(arr1[i]);
            else
                break;
        }

        // for(int i = 0 ; i < (int)arr1.size() ; i++)
        //     cout << arr3[i]->data << ",";
        // cout << endl;
        return arr3.back();
    }


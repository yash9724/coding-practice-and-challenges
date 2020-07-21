// BST: Insertion
// https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem
// status: solved



/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/  
    Node *createNode(int data){
        return new Node(data);
    }

    Node * insert(Node * root, int data) {

        if(!root)
            return createNode(data);

        if(data < root->data){
            root-> left = insert(root->left, data);
        }

        if(data > root->data){
            root->right = insert(root->right, data);
        }

        return root;
    }


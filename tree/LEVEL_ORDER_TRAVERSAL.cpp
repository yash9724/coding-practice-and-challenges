// Tree: Level Order Traversal
// https://www.hackerrank.com/challenges/tree-level-order-traversal/problem
// status: solved


/*
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

    void levelOrder(Node * root) {

        if(!root)
            return;

        queue<Node*> q;

        q.push(root);

        while(q.size()){

            cout << root->data <<" ";
            
            if(root->left)
                q.push(root->left);
            
            if(root->right)
                q.push(root->right);

            q.pop();
            root = q.front();
        }

    }


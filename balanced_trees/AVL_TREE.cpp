// Self Balancing Tree
// https://www.hackerrank.com/challenges/self-balancing-tree/problem
// status: solved

/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

node * newNode(int val){
    node* temp = new node;
    temp->val =val;
    temp->left = NULL;
    temp->right = NULL;
    temp->ht = 0;
    return temp;
}

int height(node* N){
    if(!N)
        return -1;
    return N->ht;
}

int balanceFactor(node* N){
    if(!N)
        return 0;
    return height(N->left) - height(N->right); 
}

node* leftRotate(node* p){
    node* a = p->right;
    p->right = a->left;
    a->left = p;
    
    // update heights
    p->ht = max(height(p->left), height(p->right)) + 1;
    a->ht = max(height(a->left), height(a->right)) + 1;
    
    // return new root
    return a;
}

node* rightRotate(node* p){
    node* a = p->left;
    p->left = a->right;
    a->right = p;
    
    // update heights 
    p->ht = max(height(p->left), height(p->right)) + 1;
    a->ht = max(height(a->left), height(a->right)) + 1;
    
    // return new root
    return a;
}
node * insert(node * root,int val)
{
	if(!root)
        return newNode(val);
    else if(val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    
    root->ht = max(height(root->left), height(root->right)) + 1;
    
    int bf = balanceFactor(root);
    
    // left-left imbalance
    if(bf > 1 && val < root->left->val)
        return rightRotate(root);
    // left-right imbalance
    else if(bf > 1 && val > root->left->val){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    //right-right imbalance
    else if(bf < -1 && val > root->right->val)
        return leftRotate(root);
    // right-left imbalance
    else if(bf < -1 && val < root->right->val){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    // if root has not changed
    return root;
}
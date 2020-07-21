// Tree: huffman decoding
// https://www.hackerrank.com/challenges/tree-huffman-decoding/problem
// status: solved

//
//  main.cpp
//  Huffman
//
//  Created by Vatsal Chanana



/* 
The structure of the node is

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
    
} node;

*/


void decode_huff(node * root, string s) {

    if(!root || s.length() == 0)
        return;

    // cout << s << endl;

    node *ptr = root;

    for(int i = 0 ; i < s.length() ; i++){
        
        if(s[i] == '0' && ptr->left){
            ptr = ptr -> left;
            if(ptr->data){
                cout<<ptr->data;
                ptr = root;
            }
        }
        else if(s[i] == '1' && ptr->right){
            ptr = ptr -> right;
            if(ptr->data){
                cout<<ptr->data;
                ptr = root;
            }
        }
        
    }
}


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    node* right;
    node* left;
    int val;
}node;

//inorder traversal root -> left ->  right 
//recursive

node* createNode(int data){
    node* newNode = new node();
    newNode -> right = NULL;
    newNode -> left = NULL;
    newNode -> val = data;
    return newNode;
}

void preorderTraversal(node* root){
    if(root == NULL)
        return;
    
    cout<<root -> val<<" ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

int main(){

    node* root = NULL;
    root = createNode(5);
    root -> left = createNode(3);
    root -> left -> left = createNode(1);
    root -> left -> right = createNode(4);

    root -> right = createNode(7);
    root -> right -> right = createNode(9);
    root -> right -> left = createNode(6);

    preorderTraversal(root);

    return 0;
}
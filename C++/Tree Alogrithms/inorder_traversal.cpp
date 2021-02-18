#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    node* right;
    node* left;
    int val;
}node;

//inorder traversal left -> root -> right 
//recursive

node* createNode(int data){
    node* newNode = new node();
    newNode -> right = NULL;
    newNode -> left = NULL;
    newNode -> val = data;
    return newNode;
}

void inorderTraversal(node* root){
    if(root == NULL)
        return;
    
    inorderTraversal(root -> left);
    cout<<root -> val<<" ";
    inorderTraversal(root -> right);
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

    inorderTraversal(root);

    return 0;
}
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


void levelorderTraversal(node* root){
    if(root == NULL)
        return;

    queue<node* > q;
    q.push(root);

    while(q.size() > 0){
        node* front = q.front();
        q.pop();
        cout<<front->val<<" ";

        if(front -> left)
            q.push(front -> left);
        if(front -> right)
            q.push(front -> right);
    }
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

    levelorderTraversal(root);

    return 0;
}
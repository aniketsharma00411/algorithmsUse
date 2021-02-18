#include<bits/stdc++.h> 
using namespace std; 
  

typedef struct node  
{ 
    int val;
    node* left; 
    node* right; 
}node; 
  
/* Helper function that allocates a new node with  
the given data and NULL left and right pointers. */
node* createNode(int data){
    node* newNode = new node();
    newNode -> right = NULL;
    newNode -> left = NULL;
    newNode -> val = data;
    return newNode;
}
  
  
/* Change a tree so that the roles of the left and  
    right pointers are swapped at every node. 
  
So the tree... 
    4 
    / \ 
    2 5 
    / \ 
1 3 
  
is changed to... 
    4 
    / \ 
    5 2 
        / \ 
    3 1 
*/
void mirror(node* root)  
{ 
    if (root == NULL)  
        return;  
    else
    { 
        node* temp; 
          
        /* do the subtrees */
        mirror(root->left); 
        mirror(root->right); 
      
        /* swap the pointers in this node */
        temp = root->left; 
        root->left = root->right; 
        root->right = temp; 
    } 
}  
  
/* Helper function to print  
Inorder traversal.*/
void inOrder(node* root)  
{ 
    if ( root == NULL)  
        return; 
      
    inOrder(root->left); 
    cout << root -> val << " "; 
    inOrder(root->right); 
}  
  
  
// Driver Code 
int main() 
{ 
    node *root = createNode(1); 
    root->left = createNode(2); 
    root->right = createNode(3); 
    root->left->left = createNode(4); 
    root->left->right = createNode(5);  
      
    /* Print inorder traversal of the input tree */
    cout << "Inorder traversal of the constructed"
         << " tree is" << endl; 
    inOrder(root); 
      
    /* Convert tree to its mirror */
    mirror(root);  
      
    /* Print inorder traversal of the mirror tree */
    cout << "\nInorder traversal of the mirror tree"
         << " is \n";  
    inOrder(root); 
      
    return 0;  
} 
#include <bits/stdc++.h>
using namespace std;


/*
	Worst case time complexity: O(n)
	Auxiliary space complexity: O(h); where h = height of binary tree
*/


struct Node {
	int data;
	Node *left;
	Node *right;

	Node(int value) {
		data = value;
		left = NULL;
		right = NULL;
	}
};


int isBalanced(Node *root) {
	if (root == NULL) return 0;

	int leftHeight = isBalanced(root->left);
	if (leftHeight == -1) return -1;

	int rightHeight = isBalanced(root->right);
	if (rightHeight == -1) return -1;

	if (abs(leftHeight - rightHeight) > 1) return -1;
	else return 1 + max(leftHeight, rightHeight);
}


int main() {
	Node *root = new Node(10);
	// left
	root->left = new Node(20);
	root->left->left = new Node(30);
	root->left->right = new Node(40);
	// right
	root->right = new Node(50);
	root->right->right = new Node(60);
	
	cout << "Entered tree is balanced? "
		<< (isBalanced(root) != -1 ? "true" : "false")
		<< "\n";

	return 0;
}
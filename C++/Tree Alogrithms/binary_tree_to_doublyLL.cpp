#include <bits/stdc++.h>
using namespace std;


struct Node {
	int data;
	Node* left;
	Node* right;
	
	Node(int value) {
		data = value;
		left = NULL;
		right = NULL;
	}
};


void printDoublyLL(Node *head) {
	for (Node *itr = head; itr != NULL; itr = itr->right) {
		cout << itr->data << " ";
	}
	cout << "\n";
}


Node *prevNode = NULL;
Node *BT2DLL(Node *root) {
	if (root == NULL) {
		return root;
	}
	
	Node *head = BT2DLL(root->left);
	if (prevNode == NULL) {
		// Make sure that left most element is head
		head = root;
	} else {
		// prev is set, point current's left as prev
		root->left = prevNode;
		prevNode->right = root;
	}
	prevNode = root;
	BT2DLL(root->right);
	
	return head;
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
	
	Node *doublyLL = BT2DLL(root);
	printDoublyLL(doublyLL);

	return 0;
}

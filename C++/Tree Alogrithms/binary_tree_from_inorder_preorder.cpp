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


void printLevelWithLine(Node *root) {
	if (root == NULL) {
		return;
	}
	queue<Node*> q;
	
	q.push(root);
	while (!q.empty()) {
		int count = q.size();
		for (int i = 0; i < count; ++i) {
			Node *curr = q.front();
			q.pop();
			cout << curr->data << " ";
			if (curr->left != NULL) {
				q.push(curr->left);
			}
			if (curr->right != NULL) {
				q.push(curr->right);
			}
		}
		cout << "\n";
	}
}


int preIndex = 0;
Node *binTreeInPre(int in[], int pre[], int indexStart, int indexEnd) {
	if (indexStart > indexEnd) {
		return NULL;
	}
	Node *root = new Node(pre[preIndex++]);
	
	int inIndex;
	// Can be replaced by hashmap for reducing time complexity
	for (int i = indexStart; i <= indexEnd; ++i) {
		if (in[i] == root->data) {
			inIndex = i;
			break;
		}
	}
	
	root->left = binTreeInPre(in, pre, indexStart, inIndex - 1);
	root->right = binTreeInPre(in, pre, inIndex + 1, indexEnd);
	
	return root;
}


int main() {
	int tSize;
	cout << "Enter size of tree: ";
	cin >> tSize;
	
	int in[tSize];
	cout << "Enter inorder values: ";
	for (int i = 0; i < tSize; ++i) {
		cin >> in[i];
	}
	
	int pre[tSize];
	cout << "Enter preorder values: ";
	for (int i = 0; i < tSize; ++i) {
		cin >> pre[i];
	}
	
	Node *root = binTreeInPre(in, pre, 0, tSize - 1);
	printLevelWithLine(root);

	return 0;
}

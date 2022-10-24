#include <iostream>
using namespace std;

class BTNode {
public:
	int elem;
	BTNode *left, *right;
public:
	int inOrder(BTNode* node, int k);
	void printInOrder(BTNode * node);
};

BTNode* newNode(int data) {
	BTNode* node = new BTNode;
	node->elem = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int BTNode::inOrder(BTNode * node, int k) {
	if (node == NULL) {
		return NULL;
	}
	if (node->elem >= k) {
		return node->elem;
	}
	inOrder(node->left, k);
	inOrder(node->right, k);
}

void BTNode::printInOrder(BTNode * node) {
	if (node == NULL) {
		return;
	}
	printInOrder(node->left);
	cout << node->elem << " ";
	printInOrder(node->right);
}

int main() {
	BTNode a;
	BTNode* root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(8);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->left = newNode(7);
	root->right->right = newNode(10);
	a.printInOrder(root);
	cout << endl;
	cout << "First number greater than k in traversal is: " << a.inOrder(root, 6);

	return 0;
}


#include <iostream> 
using namespace std;

class BTNode {
public:
	int elem;
	BTNode *left, *right;
public:
	void postOrder(BTNode* node);
};

BTNode* newNode(int data) {
	BTNode* node = new BTNode;
	node->elem = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void BTNode::postOrder(BTNode * node) {
	if (node == NULL) return;
	postOrder(node->left);
	postOrder(node->right);
	cout << node->elem << " ";
}

int main() {
	BTNode a;
	BTNode* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	a.postOrder(root);

	return 0;
}


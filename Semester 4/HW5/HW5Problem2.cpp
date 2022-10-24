#include <iostream> 
using namespace std;

int MAX = 100; //min and max are already set for now 
int MIN = 1;

class BTNode {
public:
	int elem;
	BTNode *left, *right;
public:
	void postOrder(BTNode* node);
	int isBSTUtil(BTNode* node, int min, int max);
	int isBST(BTNode * node);
};

BTNode* newNode(int data) {
	BTNode* node = new BTNode;
	node->elem = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void BTNode::postOrder(BTNode* node) {
	if (node == NULL) return;
	postOrder(node->left);
	postOrder(node->right);
	cout << node->elem << " ";
}

int BTNode::isBSTUtil(BTNode* node, int min, int max) {
	if (node == NULL)
		return 1;

	if (node->elem < min || node->elem > max)
		return 0;

	return
		isBSTUtil(node->left, min, node->elem - 1) &&
		isBSTUtil(node->right, node->elem + 1, max); 
}

int BTNode::isBST(BTNode* node) {
	return (isBSTUtil(node, MIN, MAX));
}

int main() {
	BTNode a;
	BTNode* root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(8);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->left = newNode(7);
	root->right->right = newNode(100);
	a.postOrder(root);
	cout << endl;

	if(a.isBST(root))
		cout << "It is a BST" << endl;
	else
		cout << "It is not a BST" << endl;

	return 0;
}




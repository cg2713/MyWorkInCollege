#ifndef BST_hpp
#define BST_hpp

#include <iostream>

using namespace std;

class BST{
private:
    class leaf{
        public:
        leaf* right;
        leaf* left;
        int elem;
    };
    
    leaf* root;
    //leaf* parent;
public:
    leaf* newNode(int data);
    void postOrder(leaf * node) 
};

leaf* newNode(int data) {
	BST::leaf* node = new leaf;
	node->elem = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void BST::postOrder(leaf * node) {
	if (node == NULL) return;
	postOrder(node->left);
	postOrder(node->right);
	cout << node->elem << " ";
}

//
//  Binary Search Tree.hpp
//  
//
//  Created by Christopher Garcia on 2/18/20.
//

#ifndef Binary_Search_Tree_hpp
#define Binary_Search_Tree_hpp

#include <stdio.h>

using namespace std;

class BST{
private:
    class leaf{
        public:
        leaf* right;
        leaf* left;
        leaf* parent;
        int elem;
    };
    leaf* root;
    
public:
    BST();
    ~BST();
    void postOrderTraversal(leaf* node);
    bool BSTP(leaf* node);
    void add(int a);
};

BST::BST(){
    root = NULL;
    /*root->left = NULL;
    root->right = NULL;*/
}

BST::~BST(){
    printf("hello");
}
/*
int left(int node) {
    return (node * 2) + 1;
}

int right(int node) {
    return (node * 2) + 2;
}*/

bool BST::BSTP(leaf* node){  
    if (node == NULL)  
        return true;  

    /* false if left is > than node */
    if (node->left != NULL && node->left->elem > node->elem)  
        return false;  

    /* false if right is < than node */
    if (node->right != NULL && node->right->elem < node->elem)  
        return false;  

    /* false if, recursively, the left or right is not a BST */
    if (!BSTP(node->left) || !BSTP(node->right))  
        return false;  

    /* passing all that, it's a BST */
        return true;  
}
v ‘
void BST::postOrderTraversal(leaf* node){
    /*Algorithm Postorder(tree)
    1. Traverse the left subtree, i.e., call Postorder(left-subtree)
    2. Traverse the right subtree, i.e., call Postorder(right-subtree)
    3. Visit the root.*/
	if(node != NULL){
		postOrderTraversal(node->left);
		postOrderTraversal(node->right);
		cout << node->elem << ' ';
	}
    
    
}

void BST::add(int a){
    typename BST::leaf* last = new leaf;
    
    last->elem = a;
    last->right = NULL;
    last->left = NULL;
    
    if (root == NULL) {
        if(root->elem < last->elem){
            root->left = last;
        }
        else{
            root->right = last;
        }
    }
    else {
        // Creates a temp node and sets it to root
        BST::leaf* temp = new leaf;
        
        temp = root;
        
        // Uses temp to find the last node
        while (temp->left != NULL or temp->right != NULL) {
            if(temp->elem < temp->parent->elem){
                temp = temp->left;
			}
            else{
                temp = temp->right;
            }
        }
        
        if(temp->elem < temp->parent->elem){
            temp->left = last;
		}
        else{
            temp->right = last;
        }
    }
}




#endif /* Binary_Search_Tree_hpp */

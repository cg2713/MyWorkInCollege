//
//  Binary Search Tree.hpp
//  
//
//  Created by Christopher Garcia on 2/18/20.
//

#ifndef Binary_Search_Tree_hpp
#define Binary_Search_Tree_hpp

#include <iostream>

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
    //leaf* parent;
public:
    
    BST();
    ~BST();
    void ChRoot(int a);
    void postOrderTraversal(leaf* node);
    bool BSTP(leaf* node);
    void add(int a);
    leaf* getRootP();
};

BST::BST(){
    root = NULL;
    
    /*root->left = NULL;
    root->right = NULL;*/
}
BST::leaf* BST::getRootP(){
    return root;
}
void BST::ChRoot(int a){
    root->elem = a;
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

bool BST::BSTP(BST::leaf* node){
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
    BST::leaf* newLeaf = new leaf;

    newLeaf->elem = a;
    newLeaf->right = NULL;
    newLeaf->left = NULL;
    
    if (root == NULL) {
        if(root->elem < newLeaf->elem){
            root->left = newLeaf;
        }
        else{
            root->right = newLeaf;
        }
    }
    
    else{
        BST::leaf* temp = new leaf;
        temp = root;
        while(temp->right != NULL or temp->left != NULL){
            if(temp->right->elem < newLeaf->elem){
                if(temp->right == NULL){
                    temp->right = newLeaf;                
                }
                else{
                    temp = temp->right;                
                }
            }
            else{
                if(temp->left == NULL){
                    temp->left = newLeaf;                
                }
                else{
                    temp = temp->left;                
                }
            }
        }
    }
}


#endif /* Binary_Search_Tree_hpp */

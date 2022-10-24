/*
Name : Christopher Garcia
Class : sp20-CS295
File : BST.cpp
Status : incomplete (segmentation faults) tree unable to generate

Description : this program is suppose to be able to take a BST and print out its rows based off of H 
EX
	2
     2.    2
3.   3.  3.  3.
 
2
2 2
3 3 3 3


*/





#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class node{
public:
	node* right;
	node* left;
	int val;
};

void postOrderTraversal(node* node){
    /*Algorithm Postorder(tree)
    1. Traverse the left subtree, i.e., call Postorder(left-subtree)
    2. Traverse the right subtree, i.e., call Postorder(right-subtree)
    3. Visit the root.*/
	if(node != NULL){
		postOrderTraversal(node->left);
		postOrderTraversal(node->right);
        cout << node->val << ' ';
        
	}
    
    
}

node* makeTree(){
	string bc[] = {"l", "ll", "lr", "lrr","lrrl", "lll", "llr", "r", "rr", "rrr", "rl", "rlr", "rlrl", "rlrlr", "rlrr"};
	int ab[] = {6, 271 , 561,  3 , 17 ,  28, 0, 6, 271, 28, 2, 1, 401, 641, 257};
	node* root;
	root->val = 314;
	for(int I = 0; I <= 15; I++){
		node* a = new node;
		node* b = root;
		for(int j = 0; j <= bc[I].size(); j++){
			if(bc[I][j] == 'l'){
				 b = b->left;
				 if(bc[I].size() == j)
					b->left = a;
			}
			if(bc[I][j] == 'r'){
				b = b->right;
				if(bc[I].size() == j)
					b->right = a;
			}
			
		}
		
		a->val = ab[I];
		
		
		
	}
	return root;
}
void printNode(node* root, string location){
	for(int I = 0; I <= location.size(); I++){
		if(location[I] == 'l'){
			root = root->left;
		}
		if(location[I] == 'r'){
			root = root->right;
		}
	}
	cout << root->val << " ";
}

void printRows(node* root){
	string bc[] = {"l", "ll", "lr", "lrr","lrrl", "lll", "llr", "r", "rr", "rrr", "rl", "rlr", "rlrl", "rlrlr", "rlrr"};
	for(int I = 0; I <= 3; I++){
		for(int j = 0; j <= bc[I].size(); j++){
			if(bc[j].size() <= I){
				printNode(root, bc[j]);
			}
		}
	}
}

   
int main(){
	cout << "test";
	node* root = makeTree();// was unable to successfully create tree segmen station fault
	//postOrderTraversal(root); 
	printRows(root);
}
	
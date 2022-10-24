/*
Name		: Joseph Pasag
Class		: CS-295
Term		: Spring 2020
File		: question1.h
Description	: Header file containing the code for question 1 of Homework 5.
*/

#include <iostream>

using namespace std;

class binSearch {
public:
    struct Node {
        int data;
        Node* parent;
        Node* lChild;
        Node* rChild;
    };

    Node* root = nullptr;

    void insert(int num) {
        Node* newNode;
        Node* nodePtr;

        newNode = new Node;
        newNode->parent = nullptr;
        newNode->lChild = nullptr;
        newNode->rChild = nullptr;
        newNode->data = num;

        if (!root) root = newNode;
        else {
            nodePtr = root;

            while (newNode->parent != nodePtr) {
                if (newNode->data <= nodePtr->data) {
                    if (nodePtr->lChild == nullptr) {
                        newNode->parent = nodePtr;
                        nodePtr->lChild = newNode;
                    }
                    else {
                        nodePtr = nodePtr->lChild;
                    }
                }
                else {
                    if (nodePtr->rChild == nullptr) {
                        newNode->parent = nodePtr;
                        nodePtr->rChild = newNode;
                    }
                    else {
                        nodePtr = nodePtr->rChild;
                    }
                }
            }
        }
    }

    void treeWalk(Node* currNode) {
        if (currNode != nullptr) {
            treeWalk(currNode->lChild);
            treeWalk(currNode->rChild);
            cout << currNode->data << endl;
        }
    }

    void postOrderTraverse() {
        Node* nodePtr;

        if (!root) cout << "ERROR: Unable to traverse tree. No Root." << endl;
        else {
            nodePtr = root;
            treeWalk(nodePtr);
        }
    }
};



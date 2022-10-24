/*
Name		: Joseph Pasag
Class		: CS-295
Term		: Spring 2020
File		: question1.h
Description	: Header file containing the answer for question 1 of Homework 3
*/

#include <iostream>

using namespace std;

class linkedList {
public:
	struct Node {
		double data;
		Node* next;
	};

	Node* head = nullptr;

	void traverse() {
		Node* nodePtr;

		if (!head) cout << "No list elements." << endl;
		else {
			nodePtr = head;
			while (nodePtr != nullptr) {
				cout << nodePtr->data;
				if (nodePtr->next) cout << ",";
				cout << " ";
				nodePtr = nodePtr->next;
			}
		}
		cout << endl;
	}
	
	void append(double num) {
		Node* newNode;
		Node* nodePtr;

		newNode = new Node;
		newNode->data = num;
		newNode->next = nullptr;

		if (!head) head = newNode;
		else {
			nodePtr = head;
			while (nodePtr->next) {
				nodePtr = nodePtr->next;
			}
			nodePtr->next = newNode;
		}
	}

	void insert(Node* a, double num) {
		Node* newNode;
		Node* nodePtr;
		

		newNode = new Node;
		newNode->data = num;
		newNode->next = nullptr;

		if (a->data > num) {
			nodePtr = a;
			a = newNode;
			a->next = nodePtr;
		}
		else {
			nodePtr = a;
			while (nodePtr->next) {
				if ((nodePtr->next->data) > (newNode->data)) {
					newNode->next = nodePtr->next;
					nodePtr->next = newNode;
					return;
				}
				nodePtr = nodePtr->next;
			}
			nodePtr->next = newNode;
		}
	}

	Node* merge(Node* a, Node* b) {
		Node* prevA;
		Node* prevB;
		Node* ptrNodeA;
		Node* ptrNodeB;

		ptrNodeA = a;
		ptrNodeB = b;
		prevA = nullptr;
		prevB = nullptr;

		while(ptrNodeB != nullptr) {
		//while (ptrNodeA != nullptr && ptrNodeB != nullptr) {
			insert(a, ptrNodeB->data);
			ptrNodeB = ptrNodeB->next;
			/*
			if (ptrNodeA->data > ptrNodeB->data) {
				if (prevA) {
					prevA->next = ptrNodeB;
					prevA = prevA->next;
				}
				else prevA = ptrNodeB;
				ptrNodeB = ptrNodeB->next;
				prevA->next = ptrNodeA;
			}
			else {
				if (prevB) {
					prevB->next = ptrNodeA;
					prevB = prevB->next;
				}
				else prevB = ptrNodeA;
				ptrNodeA = ptrNodeA->next;
				prevB->next = ptrNodeB;
			}
			*/
		}

		//return (a > b) ? b : a;
		return a;
	}
};

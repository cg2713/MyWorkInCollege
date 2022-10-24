/*
Name		: Joseph Pasag
Class		: CS-295
Term		: Spring 2020
File		: question2.h
Description	: Header file containing the answer for question 2 of Homework 3
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class queue {
public:
	struct Node {
		double data;
		Node* next;
	};

	Node* head = nullptr;
	Node* last = nullptr;

	void size() {
		Node* nodePtr;
		int count = 0;

		cout << "Size: ";
		if (!head) cout << "0" << endl;
		else {
			nodePtr = head;
			while (nodePtr != nullptr) {
				count++;
				nodePtr = nodePtr->next;
			}
			cout << count << endl;
		}
		cout << endl;
	}

	void allocate(int s) {
		Node* newNode;
		Node* nodePtr;

		
		for (int i = 0; i < s; i++) {
			newNode = new Node;
			newNode->data = NULL;
			newNode->next = nullptr;

			if (!head) {
				head = newNode;
				last = head;
			}
			else {
				nodePtr = head;
				while (nodePtr->next) {
					nodePtr = nodePtr->next;
				}
				nodePtr->next = newNode;
			}
		}
		cout << s << " spaces allocated." << endl;
	}

	void enqueue(double num) {
		Node* newNode;

		newNode = new Node;
		newNode->data = num;
		newNode->next = nullptr;

		last->next = newNode;
		last = last->next;
	}

	void dequeue() {
		Node* temp;
		
		if (head) {
			temp = head;
			head = head->next;
			delete temp;
		}

		if (head) cout << "New head: " << head->data << endl;
		else cout << "Queue is empty." << endl;
		
	}
};
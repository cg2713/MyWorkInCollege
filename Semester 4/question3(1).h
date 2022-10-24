/*
Name		: Joseph Pasag
Class		: CS-295
Term		: Spring 2020
File		: question3.h
Description	: Header file containing the answer for question 3 of Homework 3
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class stack {
public:
	struct Node {
		double data;
		Node* next;
	};

	Node* head = nullptr;
	Node* maxHead = nullptr;
	double max = NULL;

	bool empty() {
		if (!head) return true;
		return false;
	}

	void push(double num) {
		Node* newNode;
		Node* maxNode;

		
		newNode = new Node;
		newNode->data = num;
		maxNode = new Node;
		maxNode->data = num;

		if (!maxHead || max <= num) {
			max = num;
			maxNode->next = maxHead;
			maxHead = maxNode;
		}
		newNode->next = head;
		head = newNode;
	}

	void pop() {
		Node* temp;
		Node* maxTemp;

		if (empty()) cout << "Stack is empty" << endl;
		else {
			if (head->data == max) {
				maxTemp = maxHead;
				maxHead = maxHead->next;
				max = maxHead->data;
				delete maxTemp;
			}
			temp = head;
			head = head->next;
			delete temp;
		}
	}

	void maximum() {
		
		cout << "Maximum number is " << max << endl;
	}
};
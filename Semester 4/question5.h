/*
Name		: Joseph Pasag
Class		: CS-295
Term		: Spring 2020
File Name	: question5.h
Description	: Header file containing the code to answer Question 5 of Homework 4.
*/

#include <iostream>

using namespace std;

/************************NOTE: YOU MUST INCLUDE THE SIZE OF THE ARRAY WHEN CALLING buildHeap************************/

int left(int node) {
	return (node * 2) + 1;
}

int right(int node) {
	return (node * 2) + 2;
}

void swap(int *arr, int a, int b) {
	int temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void heapify(int* arr, int node, int size) {
	int l, r, largest;

	l = left(node);
	r = right(node);

	if (l <= size && arr[l] > arr[node]) largest = l;
	else largest = node;
	if (r <= size && arr[r] > arr[largest]) largest = r;
	if (largest != node) {
		swap(arr, node, largest);
		heapify(arr, largest, size);
	}
}

void buildHeap(int* arr, int size) {
	int s = size;

	for (int i = (s / 2); i >= 0; i--) {
		heapify(arr, i, size);
		for (int j = 0; j < 11; j++) {
			cout << arr[j] << " ";
		}
		cout << endl << endl;
	}
}

void maxes(int* arr, int k, int size) {
	int max;

	if (size < 1) {
		cout << "*****ERROR: Cannot extract max - Heap size is less than 1" << endl;
		exit(1);
	}

	for (int i = 0; i < k; i++) {
		max = arr[0];
		arr[0] = arr[size];
		size--;
		heapify(arr, 0, size);
		cout << i + 1 << ": " << max << endl;
	}
}
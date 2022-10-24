#include "list.hpp"

template <typename T>
void list<T>::reverse(){
    typename list<T>::Node* current = head;
    typename list<T>::Node* prev = NULL, *next = NULL;
	while (current != NULL) { 
		next = current->next; 
		current->next = prev; 
		prev = current; 
		current = next; 
	} 
	head = prev; 
}

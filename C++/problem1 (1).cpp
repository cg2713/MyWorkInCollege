#include "list.hpp"
#include <iostream>

template <typename T>
list<T>::list(){
    head = NULL;
}

template <typename T>
list<T>::~list(){
    while(!empty()){
        typename list<T>::Node* old = head;
        int v = head->elem;
        head = old->next;
        delete old;
        
    }
    cout << "deleting" << endl;
}


template <typename T>
ostream& operator<<(ostream& out, const list<T>& sl) {
	typename list<T>::Node* p = sl.head;
	out << "HEAD" << "->";
	while(p != NULL) {
		out << p->elem << "->";
		p = p->next;
	}
	out << "NULL";
	return out;
}

template <typename T>
void list<T>::addBack(const T& e){ // if its void dount change to int
    typename list<T>::Node* last = new Node;

    last->elem = e;
    last->next = NULL;

    if (head == NULL) {
        head = last;
    }
    else {
        // Creates a temp node and sets it to head
        typename list<T>::Node* temp = new Node;

        temp = head;

        // Uses temp to find the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Appends the last node with last
        temp->next = last;
    }
}

template <typename T>
void list<T>::addFront(const T& e) {
    typename list<T>::Node* v = new Node;
    v->elem = e;
    v->next = head;
    head = v;
}

template <typename T>
bool list<T>::remove(T v) {
    typename list<T>::Node* p1 = head;
    typename list<T>::Node* p2 = p1;
    if(head->elem == v)
        exit(1);
    while(p1 != NULL) {
        if(p1->elem == v) {
            p2->next = p1->next;
            delete p1;
            return true;
        }
        p2 = p1;
        p1 = p1->next;
    }
}
template <typename T>
bool list<T>::empty() const{
    return head == NULL;
}

template <typename T>
void list<T>::sort() { 
    int swapped; 
    typename list<T>::Node* start = head;
    typename list<T>::Node* ptr1 = head; 
    typename list<T>::Node* lptr = NULL; 
    /* Checking for empty list */
    if (start == NULL) 
        return;
    do{ 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) { 
            if (ptr1->elem > ptr1->next->elem){
                
                int temp = ptr1->elem; 
                ptr1->elem = ptr1->next->elem; 
                ptr1->next->elem = temp; 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    }while (swapped); 
} 





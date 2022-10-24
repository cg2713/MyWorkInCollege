#include "TList.hpp"

template<typename T>
void list<T>::merge(list<T> h2) {
    typename list<T>::Node* p1 = head;
    typename list<T>::Node* p2 = h2.head;
    
    while (p2 != NULL) {
	if(p2->elem < p1->elem){
	    p1->next = p2;
	}
	else{
	    p2 = p2->next;
	}
    }
}

































































}

#include "list.hpp"

template<typename T>
void list<T>::duplicates(){
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
            if (ptr1->elem == ptr1->next->elem){
                remove(ptr1->elem);
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    }while (swapped); 
}

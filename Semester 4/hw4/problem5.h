//
//  problem5.h
//

#ifndef problem5_h
#define problem5_h

#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

template<typename T> class list;
template<typename T> ostream& operator<<(ostream& out, const list<T>& sl);

template<typename T>
class list{
private:
    class Node{
    public:
        T elem;
        Node *next;
    };
    Node* head;
    
public:
    list<T>();
    ~list<T>();
    void addBack(const T& e);
    void sort();
    void reverse();
    friend ostream& operator<< <T>(ostream& out, const list<T>& sl);
    T operator[](int pos);
    
};
template <typename T>
list<T>::list(){
    head = NULL;
}

template <typename T>
list<T>::~list(){
    while(head != NULL){
        typename list<T>::Node* old = head;
        //int v = head->elem;
        head = old->next;
        delete old;
    }
}

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
            if (ptr1->elem < ptr1->next->elem){
                
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

template< typename T >
T list<T>::operator[](int pos) {
    typename list<T>::Node *current = new Node;
    int i = 0;
    
    for(current = head ;current != NULL;current = current->next) {
        if(i == pos) {
            return current->elem;
        }
        i++;
    }
    return 0;
    
}


#endif /* problem5_h */

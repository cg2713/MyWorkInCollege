#ifndef SingledLinkedList_hpp
#define SingledLinkedList_hpp
#include <iostream>
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
    bool empty() const;
    int len() const;
    const T &front() const;
    void addFront(const T& e);
    T removeFront();
    bool remove(T v);
    T greatestValue();
    void addBack(const T& e);
    //void addSorted(int a);
    void clear();
    void sort(); // finish this
    void reverse();// finish this
    friend ostream& operator<< <T>(ostream& out, const list<T>& sl);
	T operator[](int pos);
    void meage(list<T> a);
};


template <typename T>
list<T>::list(){
    head = NULL;
}

template <typename T>
list<T>::~list(){
    clear();
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
bool list<T>::empty() const{
    return head == NULL;
}
template <typename T>
int list<T>::len() const{
    typename list<T>::Node* p = head;
    int i = 0;
    while(p != NULL){
        i++;
        p = p->next;    
    }
    return i;
}
template <typename T>
T const &list<T>::front() const {
    return head->elem;
}

template <typename T>
void list<T>::addFront(const T& e) {
    typename list<T>::Node* v = new Node;
    v->elem = e;
    v->next = head;
    head = v;
}

template <typename T>
T list<T>::removeFront() {
    typename list<T>::Node* old = head;
    int v = head->elem;
    head = old->next;
    delete old;
    return v;
}

template <typename T>
bool list<T>::remove(T v) {
    typename list<T>::Node* p1 = head;
    typename list<T>::Node* p2 = p1;
    if(head->elem == v)
        return removeFront();
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
void list<T>::clear(){
    while(!empty())
        removeFront();
}


template<typename T>
void list<T>::meage(list<T> a){
	typename list<T>::Node* p1 = head;
    typename list<T>::Node* p2 = a.head;
	
    for(int i = 0; i <= len(); i++){
        for(int j = 0; j <= a.len(); j++){
            if(p1->elem > a[j]){
               p2 = p1->next;
            }
            p2 = p2->next;
        }
        p2 = a.head;
        p1 = p1->next;
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

#endif

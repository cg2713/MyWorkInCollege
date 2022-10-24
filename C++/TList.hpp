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
void list<T>::sort(){// finish this
    typename list<T>::Node* current = head;
    typename list<T>::Node* prev = NULL, *next = NULL;
	T temp;
	while(current != NULL){
		while(next != NULL){
			if(next->elem >= current->elem){
				temp = current->elem;
				current->elem = next->elem;
				next->elem = temp;
			}
		}
	}
} 
template <typename T>
void list<T>::reverse(){// finish this
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

#endif

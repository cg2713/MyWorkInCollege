//
//  slikedist.hpp
//  
//
// chapter 5-6
//

#ifndef slikedist_hpp
#define slikedist_hpp

#include <stdio.h>
class SLinkedList {
private:
    class ~snode{
    public:
    int elem;
    SNode* next;
    friend class SLinkedList;
    
    }
private:
SNode* head;

public:
    SLinkedList();
    ~SLinkedList();
    bool empty() const; // define here first
    int len() const;
    const int& fromt() const;
    void addFront(const int& e);
    int removeFront();
    bool remove(int v);
    friend std::ostream& operator<<(std::ostream& out const SLinkedList); // the operator is like well the terminal it printing the list of SLinkedList
}

SLinkedList::SLinkedList() : head(NULL) {}

SLinkedList::~SLinkedList{
    while(!empty())
        removeFront();
}

bool SLinkedList::empty() const{ // define function here
    return head == NULL;
}

int SLinkedList::len() const {
    SLinkedList::SNode* p = head;
    int i = 0;
    while(p != NULL){
        i++
        p == p->next;  // (*p).next
        
    }
    return i;
}
const int& SLinkedList::front() const{
    return head->elem;
}

void SLinkedList::addFront(const int& e){
    SLinkedList::SNode* v = new SNode;
    v->elem = e;
    v->next = head;
    head = v;
}

int SLinkedList::removeFront() { // ** first u meust declare the function
    SLinkedList::SNode* old = head;
    int v = head->elem;
    head = old->next;
    delete old; // old is a pointer to the old head
    return v;
}

bool SLinkedList::remove(int v){
    SLinkedList::SNode* p1 = head;
    SLinkedList::SNode p2 = p1;
    if(head->elem == v)
        return removeFront(); //** then u can use the function at will anywhere
    while (p1 != NULL) {
        if(p1->elem == v){
            p2->next = p1->next;
            delete p1;
            return true;
            
        }
        p2 = p1;
        p1 = p1->next;
        
        
    }
    return false;
}
#endif /* slikedist_hpp */

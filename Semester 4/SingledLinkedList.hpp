#ifndef SingledLinkedList_hpp
#define SingledLinkedList_hpp
#include <iostream>

using namespace std;
 
class list {
private:
    class Node{
    public:
        int elem;
        Node * next;    
    };
private:
    Node* head;

public:
     list();
    ~list();
    bool empty() const;
    int len() const;
    const int& front() const;
    void addFront(const int& e);
    int removeFront();
    bool remove(int v);
    int greatestValue();
    void addBack(const int& e);
    //void addSorted(int a);
    void clear();
    void sort(); // finish this
    void reverse();// finish this
    friend ostream& operator<<(ostream& out, const list& sl);
};



list::list(){
    head = NULL;
}

list::~list(){
    clear();
}
void list::sort(){// finish this

} 

void list::reverse(){// finish this

}


bool list::empty() const{
    return head == NULL;
}
int list::len() const{
    list::Node* p = head;
    int i = 0;
    while(p != NULL){
        i++;
        p = p->next;    
    }
    return i;
}
const int& list::front() const {
    return head->elem;
}

void list::addFront(const int& e) {
    list::Node* v = new Node;
    v->elem = e;
    v->next = head;
    head = v;
}
int list::removeFront() {
    list::Node* old = head;
    int v = head->elem;
    head = old->next;
    delete old;
    return v;
}
bool list::remove(int v) {
    list::Node* p1 = head;
    list::Node* p2 = p1;
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
void list::addBack(const int& e){ // if its void dount change to int
    list::Node* last = new Node;

    last->elem = e;
    last->next = NULL;

    if (head == NULL) {
        head = last;
    }
    else {
        // Creates a temp node and sets it to head
        list::Node* temp = new Node;

        temp = head;

        // Uses temp to find the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Appends the last node with last
        temp->next = last;
    }
}



ostream& operator<<(ostream& out, const list& sl) {
  list::Node* p = sl.head;
  out << "HEAD" << "->";
  while(p != NULL) {
    out << p->elem << "->";
    p = p->next;
  }
  out << "NULL";
  return out;
}

#endif

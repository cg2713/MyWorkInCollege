#ifndef list_hpp
#define list_hpp
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
    ~list<T>();;
    void addFront(const T& e);
    bool remove(T v);
    void addBack(const T& e);
    //void addSorted(int a);
    void sort(); // finish this
    void reverse();// finish this
    void duplicates();
    bool empty() const;
    friend ostream& operator<< <T>(ostream& out, const list<T>& sl);
};

#endif


#include <iostream>
#include "list.hpp"
#include "problem1.cpp"
#include "problem2.cpp"
#include "problem3.cpp"

using namespace std;

// a will travers with cout stament do to friend

int main(){
    list<int> a;
    a.addBack(5);
    a.addBack(2);
    a.addBack(6);
    a.addBack(9);
    a.addBack(5);
    a.addBack(7);

    cout << a << endl;
    a.sort();
    cout << a << endl;
    a.duplicates();
    cout << a << endl;
    a.reverse();
    cout << a << endl;
    //return 0;
}

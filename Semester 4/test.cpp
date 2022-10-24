#include <iostream>
#include "TList.hpp"

using namespace std;

int main(){
    //cout << "hello world\n";

    //cout << "hit";
    list<int> a;
    list<int> b;

    //cout << "hit"; 
    a.addBack(10);
    a.addBack(8);
    a.addBack(6);
    a.addBack(4);
    a.addBack(2);

    b.addBack(9);
    b.addBack(7);
    b.addBack(5);
    b.addBack(3);
    b.addBack(1);
    //cout << "hit";
    cout << a << endl << b << endl;

    a.merge(b);
    cout << "hit";
    cout << b;

}
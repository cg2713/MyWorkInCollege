#include <iostream>
#include "problem5.h"

int main(){
    list<int> a;

    a.addBack(6);
    a.addBack(8);
    a.addBack(4);
    a.addBack(2);
    a.addBack(8);
    a.addBack(9);
    a.addBack(43);
    a.addBack(5);
    a.addBack(33);

    a.sort();
    
    cout << a[0] << endl;
    cout << a;
}

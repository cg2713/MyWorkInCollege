#include <iostream>
#include "TList.hpp"

using namespace std;

int main(){

    list<int> a;
    list<int> b;
    list<int> res;

    a.addBack(2);
    a.addBack(4);
    a.addBack(6);
    a.addBack(8);
    a.addBack(10);

    b.addBack(1);
    b.addBack(3);
    b.addBack(5);
    b.addBack(7);
    b.addBack(9);

    res.merge(a,b);

        
    
    cout << res;
}

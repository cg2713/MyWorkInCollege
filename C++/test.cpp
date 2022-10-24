#include<iostream>
#include "TList.hpp"

using namespace std;

int main(){
    list<int> a;
    for(int i = 0; i <= 10000; i++)
        a.addBack(i);
    cout << a << endl << endl;
    a.reverse();

    cout << a << endl << endl;
}

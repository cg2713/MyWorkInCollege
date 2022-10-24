//
//  problem 1 test.cpp
//  
//
//  Created by Christopher Garcia on 2/14/20.
//

#include <stdio.h>
#include "problem5.h"

using namespace std;

int main(){
    list<int> a;
    a.addBack(8);
    a.addBack(2);
    a.addBack(5);
    a.addBack(4);
    a.addBack(9);
    a.addBack(7);
    a.addBack(27);
    a.addBack(13);
    a.addBack(89);
    
    cout << a << endl;
    
    a.sort();
    
    cout << a << endl;
    
    a.reverse();
    cout << a << endl;
    
    cout << "the largest k element is: " << a[0] << endl; 
}

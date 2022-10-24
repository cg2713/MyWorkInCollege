//
//  HW3-3.hpp
//  
//
// 
//

#ifndef HW3_3_hpp
#define HW3_3_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class stack{
private:
    vector<int> a;
public:
    stack();
    bool empty();
    int push(int b);
    void pop();
    int max();
    
};
stack::stack(){
    vector<int> a;
}
bool stack::empty(){
    return a.empty();
}

int stack::push(int b){
    int temp = 0;
    for(int i = 0; i <= a.size(); i++){
        if(a[i] < b){
            temp = a[i];
            a[i] = b;
        }
    }
    a.push_back(temp);s
}
void stack::pop(){
    a.pop_back();
}
int stack::max(){
    return a[0];
}


#endif /* HW3_3_hpp */

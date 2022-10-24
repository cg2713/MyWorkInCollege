//
//  HW3-2.hpp
//  
//
// 
//

#ifndef HW3_2_hpp
#define HW3_2_hpp

#include <stdio.h>
#include <vector>
using namespace std;
class Queue{
private:
    vector<int> a;
public:
    Queue();
    ~Queue();
    int enqueue(int b);
    void dequeue();
    int len();
    int operator[](int pos);
};

Queue::Queue(){
    vector<int> a;
}
Queue::~Queue(){
    for(int i = 0; i <= a.size(); i++){
        a.pop_back();
    }
}

int Queue::enqueue(int b){
    a.push_back(b);
}
void Queue::dequeue(){
    a.erase(a[0]);
}
int Queue::len(){
    return a.size();
}

int Queue::operator[](int pos){
    return a[pos];
}


#endif /* HW3_2_hpp */

#include <iostream>
#include <stack>
#include <string>
#include "stdio.h"
using namespace std;

int calc(int val1, int val2, char op);
int atoi(char a);

int main(){
    stack<int> a;
    string b;
    getline(cin,b);
    cout << b;
    
    for(int i = 0; i <= b.length()-1; i++){
        if(b[i] != '+' and b[i] != '-' and b[i] != '/' and b[i] != '*'){
            a.push(atoi(b[i]));        
        }    
        else{
            int temp = a.top();
            cout << temp << " ";
            a.pop();
            int temp2 = a.top();
            cout << temp2 << " ";
            a.pop();
            a.push(calc(temp, temp2,b[i]));
        }
    }
    
    cout << endl << a.top() << endl;
}

int atoi(char a){
    string num = "0123456789";
    for(int i = 0; i <= 9; i++){
        if(a == num[i])
            return i;    
    }
}

int calc(int val1, int val2, char op){
    if(op == '-'){
        return val1 - val2;    
    }
    else if(op == '+'){
        return val1 + val2;    
    }
    else if(op == '*'){
        return val1 * val2;    
    }
    else if(op == '/'){
        return val1 / val2;    
    }
}

/*
Name : Christopher Garcia
Class : sp20-CS295
File : postfixNotation.cpp
Status : completed

Description : this program is able to process post notation math

Ex
12 13 + 5 *

125 



*/




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
    string f = ""; 
    for(int i = 0; i <= b.length()-1; i++){
	//cout << " RRR" << f << "LLL ";
        if(b[i] != '+' and b[i] != '-' and b[i] != '/' and b[i] != '*' and b[i] != ' '){
	     f = f + b[i];
        }
   	else if(b[i] == ' '){
	     if(f.size() != 0){
             	a.push(stoi(f));
	     	f = "";
	     }
	     else
		continue;
	}
        else{
            int temp = a.top();
            //cout << temp << " ";
            a.pop();
            int temp2 = a.top();
            //cout << temp2 << " ";
            a.pop();
            a.push(calc(temp, temp2, b[i]));
        }
    }
    
    cout << endl << a.top() << endl;
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
    else{
        return 1;
    }
}

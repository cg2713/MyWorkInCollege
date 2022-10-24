#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    getline(cin, a);
    a += " \0";
    string BSTA[a.length()];    
    string temp = "";
    int count = 0;
    for(int i = 0; i <= a.length(); i++){
        if(a[i] != ' '){
            temp += a[i];
        }
        else{
            BSTA[count] = temp;
            temp = "";
            count++;            
        }
    }
    int tempCount = 1;
    for(int i = 0; i < count; i++){
        // attempted to print out in here
    }
    
        
}

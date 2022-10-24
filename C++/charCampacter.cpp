#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<int> packer(string);
void unpacker(vector<int>);

int main(){
	string a;
    //string b;
    //string c;
    
    getline(cin, a);
    /*cout << "add on to it\n";
    getline(cin, b);
    c = a + b;
    cout << c << endl;*/

    vector<int> d = packer(a);
    
    for(unsigned int i = 0; i <= d.size(); i++)
        cout << d[i] << ", ";
    printf("\n");
    unpacker(d);
    printf("\n");
    
    
     
}

vector<int> packer(string x){
    vector<int> y; 
    int z = 0;   
    
    for(unsigned int i = 1; i <= x.length(); i++){
        if(i%4 == 0){
            z <<= 8;
            z |= x[i];
            y.push_back(z);
            z = 0;
        }
        else{
            z <<= 8;
            z |= x[i];
        }
        
        
    }
    return y;
}

void unpacker(vector<int> x){
    vector<int> y;
    char z;   
    
    for(unsigned int i = 0; i <= x.size(); i++){
        int t = x[i];
        for(unsigned int i = 0; i <= 4; i++){
            z |= t;
            cout << z;

            t >>= 8;
        }
    }
}
    

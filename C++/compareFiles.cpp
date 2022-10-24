#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void usage(string name);

int main(int argc char** argv){
    bool equal = true;
    bool ferr = false;
    
    vector<unsigned char> buf1(1024,0);
    vector<unsigned char> buf2(1024,0);
    
    ifstream f1(argv[1], ios::in | ios::binary);
    ifstream f2(argv[2], ios::in | ios::binary);
    
    if(!f1 ||)
}


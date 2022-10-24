#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    string filename = "myfile.txt":
    istringstream iss;
    ostringstream oss;
    
    int x = 1;
    int lastpos;
    char c;
    ofstream fout;
    ifstream fin(filename.c_str(), ios::in)
    if(fin){
        cout << "file contents: " << endl;
        while(!fin.eof()){
            fin.get(c);
            cout.put(c);
        }
        cout << "reverse file contents: " << endl;
        
        fin.clear()
        
        fin.seekg(0, ios::end);
        
        lastpos = fin.tellg();
        while(x <= lastpos){
            fin.seekg(-x, ios::end);
            fin.get(c);
            oss << c;
            x++;
        }
        cout << oss.str() << endl;
        
        fout.open(("revesed_" + filename).c_str(), ios::out | ios::trunc);
        if(fout){
            istringstream iss(oss.str());
            while(true){
                c = iss.get();
                if(iss.get())
                    break;
                fout << c;
            }
            fout << endl;
            fout.flush();
            
        }
        
    }
}

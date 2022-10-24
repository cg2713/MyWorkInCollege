#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>

using namespace std;

void usage(string name);
void process(istream& in, ostream& out, int k);
char caesarCipher(char c, int k);

int main(int argc,char** argv){
    bool decrypt = false;
    int key;
    int files = 0;
    string filename1;
    string filename2;
    ifstream fin;
    ofstream fout;
    
    if(argc < 3 || argc > 5)
        usage(string(argv[0]));
    for(int i = 1; i < argc; ++i){
        string arg = string(argv[i]);
        if(arg.length() >=2 and arg[0] == '-'){
            char option = arg[1];
            if(option == 'd')
                decrypt = true;
            else if(option == 'k'){
                istringstream iss(arg.substr(2));
                iss >> key;
            }
        }else {
            files++;
            if(files == 1)
                filename1 = arg.c_str();
            else if(files == 2)
                filename2 = arg.c_str();
        }
    }
    if(files != 2)
        usage(string(argv[0]));
    
    fin.open(filename1.c_str(), ios::in | ios::binary); // ios = file in and out    ios = input outpu stream     trunc = cutting things a sort of absolut value if 2.8 was rounded it would = to 2 its integer it will always round to its integer
    /*
     
     but with ios trunic =
     
     it will remove everything in the file
     
     ios::in | ios::binary = or in bitwise
     
     */
    fout.open(filename2.c_str(), ios::out | ios::trunc | ios::binary); // | is using both && and ||       calling the class of ios and using it cast binary
    if(fin and fout){
        if(decrypt){
            key = -key;
        }
        process(fin, fout, key);
        fout.flush();
        fout.close();
        fin.close();
        if(!fout.good())
            cout << "error while closing: " << filename2 << endl;
        
    }else
        cout << "error: " << filename1 << " or " << filename2 << " could not be opened...abourting" << endl;
    return 0;
}

void usage(string name){
    cout << "usage: " << name << " [-d][-kn]infile outfile" << endl;
    exit(1);
}
void process(istream& in, ostream& out, int k){ // referncing the file both in and out permenetly
    char c;
    while(in.get(c)){
        char x = caesarCipher(c,k);
        out.write(&x, sizeof(char));
    }
}
char caesarCipher(char c, int k){
    const int VSIZE = int('Z') - int('A') + 1;
    if(isalpha(c)) // checking if alphabetic characters
        return static_cast<char>( ( ( ( (int(c) - int(isupper(c) ? 'A' : 'a') + k ) % VSIZE + VSIZE ) % VSIZE ) + int(isupper(c) ? 'A' : 'a') ) );
    else
        return c;
}


unique_ptr<int> ptr;
int* ptr;

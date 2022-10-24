#include <iostream>
#include <string>


using namespace std;

int main(){
	string input;
    cin >> input;
    
    bool up = false;
    bool down = false;    
    bool num = false;
    
    int len = input.length();

    if(len < 16 and len > 5){
        for(int i = 0; i <= len; i++){
            for(char j = 'a'; j <= 'z'; j++){
                if(input[i] == j)
                    down = true;
                }
            for(char k = 'A'; k <= 'Z'; k++){
                if(input[i] == k || input[i] == '@' || input[i] == '#' || input[i] == '$')
                    up = true;
            }
            for(int l = 0; l <= 9; l++){
                if(input[i] == l)
                    num = true;
            }
        }
        if(up and down and num)
            cout << "valid\n";
        else
            cout << "invalid\n";       
    }
    else
        cout << "too short";
}

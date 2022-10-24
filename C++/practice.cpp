#include <iostream>
#include <vector>

using namespace std;

int main(){
    int sum = 0;
    vector<int> list;
    while(true){
        int temp;
        cin >> temp;
        if(temp != 0)
            list.push_back(temp);
        else
            break;
    }
    cout << endl;
    for(int i = 0; i <= list.size()-1; i++){
        //sum = 0;
        for(int j = 0; j <= list.at(i); j++){
            sum = sum + j;
        }
        cout <<"N = "<< list.at(i) << "\t" << "sum = "<< sum << endl;
        sum = 0;
    }
}

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int FindPeak(const vector<int> &vec);

int main(){
    srand (time(NULL));
    vector <int> a;
    for(unsigned int i = 0; i < 5; i++){
        int randn = 1 + rand() % 100;
        a.push_back(randn);
    }
    for(unsigned int i = 0; i < a.size(); i++)
        cout << a[i] << ' '; 
    int peak = FindPeak(a);
    cout << "peak = " << peak << endl;
    
}

/*
Pick middle column -> const
Find 1-D peak at column
Return 1-D peak at (i,j) -> log(m)
Find 1-D peak at row i -> log(n)
Return #3 ->const
T = log(m) + log(m)
S(n,m) = const


If a[n/2 -1] > a[n/2] move left
Else if a[n/2 +1] > a[n/2], move right
Else a[n/2] is peak

*/
        //         *
        //[62, 39, 23, 69, 59]

int FindPeak(const vector<int> &vec){
    int mid = vec.size()/2;
    if(vec[mid] < vec[mid - 1] and vec[mid - 1] > vec[mid - 2])
        return vec[mid - 1];
    else if(vec[mid] < vec[mid + 1] and vec[mid + 1] > vec[mid + 2])
        return vec[mid + 1];
    else
        return vec[mid];
}





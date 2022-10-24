#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int FindPeak(const vector<int> &vec);
void bubble(vector<int> &vec);

int main(){
    srand (time(NULL));
    vector <int> a;
    for(unsigned int i = 0; i < 10000; i++){
        int randn = 1 + rand() % 1000;
        a.push_back(randn);
    }
	bubble(a);
    for(unsigned int i = 0; i < a.size(); i++){
        cout << a[i] << ", "; 
	}
	
    int peak = FindPeak(a);
	printf("\n");
    cout << "peak = " << peak << endl;
    
}
void bubble(vector<int> &vec){
	for(unsigned int i = 0; i <= vec.size(); i++){
		for(unsigned int j = 0; j <= vec.size(); j++){
			if(vec[i] <= vec[j]){
				int temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;
			}
		}
	}
}

int FindPeak(const vector<int> &vec){
    int mid = vec.size()/2;
    if(vec[mid] < vec[mid - 1] and vec[mid - 1] > vec[mid - 2])
        return vec[mid - 1];
    else if(vec[mid] < vec[mid + 1] and vec[mid + 1] > vec[mid + 2])
        return vec[mid + 1];
    else
        return vec[mid];
}






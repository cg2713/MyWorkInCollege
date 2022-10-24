#include <iostream>
#include <vector>
#include <cstdlib>
#include "stdio.h"


using namespace std;

void bubble(vector<int> &vec);
int fmax(const vector<int> &vec);
int bSearch(vector<int> &vec, int value);

int main(){
    srand (time(NULL));
    vector <int> a;
    for(unsigned int i = 0; i < 1000000; i++){
        int randn = 1 + rand() % 100000;
        a.push_back(randn);
    }
	bubble(a);
    for(unsigned int i = 0; i < a.size(); i++){
        cout << a[i] << ", "; 
	}
	
    int max = fmax(a);
	printf("\n");
    cout << "max = " << max << endl;
    
}

int fmax(const vector<int> &vec){
	int max = vec[0];
	for(int i = 1; i < vec.size(); i++){
		if(vec[i] >= max)
			max = vec[i];
	}
	return max;
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

int bSearch(vector<int> &vec, int value){
    int mid = vec.size()/2;
    int i = 0;
    while(1)
        
}






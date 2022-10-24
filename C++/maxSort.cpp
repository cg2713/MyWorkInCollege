#include <iostream>
#include <vector>
#include <cstdlib>

/*
times

sorted:
real    0m0.731s
user    0m0.703s
sys     0m0.046s

real    0m0.733s
user    0m0.718s
sys     0m0.031s

real    0m0.722s
user    0m0.703s
sys     0m0.062s

real    0m0.718s
user    0m0.671s
sys     0m0.077s

unsorted:
real    0m0.058s
user    0m0.015s
sys     0m0.015s

real    0m0.057s
user    0m0.015s
sys     0m0.015s

real    0m0.055s
user    0m0.030s
sys     0m0.000s

real    0m0.065s
user    0m0.015s
sys     0m0.015s

*/


using namespace std;

void bubble(vector<int> &vec);
int fmax(const vector<int> &vec);

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






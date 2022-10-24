#include <iostream>
using namespace std;

int main(){
	int a = 1;
	for(int i = 0; i <= 30; i++){
		a = a << 1;
		cout << a << endl;
		if(a == 0){
			cout <<"\t"<< i << endl;;
		}
	}	
}

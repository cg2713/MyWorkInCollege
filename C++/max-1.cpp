#include <iostream>
#include <vector>

using namespace std;

void maxPev(vector<int> a, int& , int&);

int main() {
    vector<int> a;
    while (true) {
        int temp;
        cin >> temp;
        if (temp != 0)
            a.push_back(temp);

        else
            break;
    }
	
	int max = a[0];
    int previous = 0;
    maxPev(a, max, previous);

    cout << max << " " << previous << endl;
    //system("pause");
}
						// max    previous
void maxPev(vector<int> a, int &b, int &c) {
    for (unsigned int i = 1; i < a.size(); i++) {
        if (a[i] >= c) {
			if(a[i] >= b){
				c = b;
				b = a[i];
			}
			else
				c = a[i];
            
        }
     }/*
     if(b == c){ // checks to see if the the frist number is the biggest
         c = 0;
         for (unsigned int i = 1; i < a.size(); i++){
             if(a[i] >= c)
                 c = a[i];
         }
     }*/
}
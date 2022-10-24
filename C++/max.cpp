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
	int previous;
	maxPev(a, max, previous);

	cout << max << " " << previous << endl;
	//system("pause");
}

void maxPev(vector<int> a, int &b, int &c) {
	for (int i = 1; i < a.size(); i++) {
		if (a[i] >= b) {
			c = b;
			b = a[i];
		}
		if(b == c){
				printf("test");
				if(c >= a[i]){
					printf("test2");
					c = a[i];
				}
			}
	}
}

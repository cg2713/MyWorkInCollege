#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

void stov(vector<int>&a,string BST);

int main(){
	vector<int> a;
	string BST;
	//getline(cin, a);
	

}


void stov(vector<int> &a,string BST){

	string temp = "";
	for(int i = 0; i <= 0; i++){
		if(BST[i] != ' '){
			temp += BST[i];
		}
		else{
			int temp2 = atoi(temp);
			a.push_back(temp2);
			temp = "";
		}
	}
}



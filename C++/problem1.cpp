#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
//#pragma warning(disable : 4996)


using namespace std;

void letterFrequencies(string File, map<char, double>& a, string line) {
	// n amuount of letter found divided by however many letter are in the string
	int x = -1;
	string sentence = line;
	int length = sentence.length();

	for (int j = 0; j <= sentence.length(); j++) {
		//x++;
		if (sentence[j] != ' ')
			x++;
	}
	
	for (int i = 0; i <= sentence.length(); i++) {

		char ltemp = sentence[i];
		double ntemp = 0.0;
		for (int k = 0; k <= sentence.length(); k++) {

			if (sentence[i] == sentence[k] ) {
				ntemp++;
			}
		}

		double temp2 = ntemp / x;
		//cout << temp2 << endl;
		a.insert(make_pair(ltemp, temp2));
		ntemp = 0;
	}
	cout << "the totalt amout of characters without spaces is: " << x << endl;
}

void print(map<char, double> a) {
	map<char, double>::iterator it = a.begin();
    
	for (it = a.begin(); it != a.end(); it++) {

		if ((it->first != NULL) and (it->second != NULL) and (it->first != ' ') and (it->first != '	'))
			cout << it->first << " = " << it->second << endl;
		
	}
}



int main() {
	string name;
	cout << "enter a file name" << endl;
	cin >> name;
	cout << setprecision(4) << fixed;
	string line = "";
	ifstream myfile(name);
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			string templine;
			getline(myfile, templine);
			line = line + templine;
		}
		myfile.close();
	}
	map<char, double> letters;

	letterFrequencies(name, letters, line);
	print(letters);
}

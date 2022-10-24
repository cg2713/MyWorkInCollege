#include <iostream>
#include <string>
#include "Source.cpp"

using namespace std;

double SDT(string type, double S, double D, double T) {

	if (type == "speed") {
		S = (D / T);
		return S;
	}
	else if (type == "distance") {
		D = (S * T);
		return D;
	}
	else if (type == "time") {
		T = (D / S);
		return T;
	}
}



int main() {
	string type;

	cout << "type: ";
	cin >> type;
	double speed = 0.0, distance = 0.0, time = 0.0;

	if (type == "speed") {
		cout << "what is the distance and time" << endl;
		cin >> distance;
		cin >> time;
	}
	else if (type == "distance") {
		cout << "what is the speed and time" << endl;
		cin >> speed;
		cin >> time;
	}
	else if (type == "time") {
		cout << "what is the distance and speed" << endl;
		cin >> distance;
		cin >> speed;
	}

	double awnser = SDT(type, speed, distance, time);



	cout << "the awnser is " << awnser << endl;
	//Input(type, speed, distance, time)



}
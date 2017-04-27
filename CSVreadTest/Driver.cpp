#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define TEST "test.csv"

bool readCSV(int thing1[]);

int main() {
	
	int thing1[10];
	readCSV(thing1);
}

bool readCSV(int thing1[]) {

	ifstream input;
	input.open(TEST);

	if (!input) {
		cout << "broke";
		return false;
	}
	

	for (int i = 0; i < 2; ++i) {
		input >> thing1[i];
	}

	cout << "\n array output test " << thing1[1];

	return true;

}
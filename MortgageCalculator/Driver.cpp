//Joshua Morse jmorse2@cnm.edu
//MorseP6
//File: Driver.cpp

#include <iostream>
#include <string>
#include <sstream> //for stringstream
#include <fstream>
#include <ctime>
#include "Functions.h"
#include "MortCalc.h"
#include "MortInfo.h"

using namespace std;


int main() {
	//Declare Variables
	string again = "yes";
	string result, filename;

	MortInfo mortData;

	Header();
	do {
		AskForLoanInfo(mortData);

		if (Validate(mortData) == false) {
			cout << "\nYour input was out of the range, please re-run the program "
				<< "\nwithin the appropriate ranges.";
		}
		else {
			WriteMort(result, filename);
			//MortCalc(mortData);
		}

		cout << "\n Do you want to run the program again? ";
		getline(cin, again);
		cin.ignore();

	} while (again == "yes");

	return 0;
}

void Header() {
	cout << "\n Joshua Morse, JMorse2@cnm.edu \n Morse P5 \n File: Driver.cpp"
		<< "\n This program is going to estimate the monthly payment for a "
		<< "\n home mortgage based off amount, interest rate, and term.";

}

void AskForLoanInfo(MortInfo &mortData) {

	float interest;
	int principal, term;

	cout << "\n What is the ammount of the loan in whole dollars? ";
	cin >> mortData.principal;

	cout << "\n Is the term 15, 25, or 30 years? ";
	cin >> mortData.term;

	cout << "\n What is the interest rate? (enter 5, for 5\%, 3.5 for 2.5\% ";
	cin >> mortData.interest;

}

bool Validate(MortInfo &mortData) {
	//MortInfo mortData;
	if (mortData.principal < 500000 && mortData.principal > 0 && mortData.term == 15 || mortData.term == 25
		|| mortData.term == 30 && mortData.interest > 0 && mortData.interest <= 10) {
		return true;
	}
	else {
		return false;
	}
}

void CalcEndOfLoan(MortInfo &mortData) {

	//MortInfo mortData;
	time_t rawTime;
	tm *OStime;
	time(&rawTime);


	//get the system time
	time(&rawTime);
	//get the local time
	OStime = localtime(&rawTime);

	//find the start of the loan
	mortData.monStart = OStime->tm_mon  + 1;
	mortData.dayStart = OStime->tm_mday;
	mortData.yearStart = OStime->tm_year + 1900;

	//find the end of the loan
	mortData.monEnd = mortData.monStart;
	mortData.dayEnd = mortData.dayStart; //come back to get the actual end date.
	mortData.yearEnd = mortData.yearStart + mortData.term;

	//define number of days in each month
	int dayCount[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
}

bool WriteMort(string result, string filename) {


	cout << "\n What is the name of the output file? ";
	getline(cin, filename);
	filename = filename + ".txt";
	//declare output file
	ofstream outputFile;
	//open file to write
	outputFile.open(filename);
	//check that file is open
	if (!outputFile) {
		cout << "\n The file was not written";
		return false;
	}

	//write the file by calling MortCalc()
	outputFile << MortCalc(mortData);
	//close the file after writing
	outputFile.close();
	cout << "\n The file was written. ";
	return true;

}

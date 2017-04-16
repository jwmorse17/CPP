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

using namespace std;


int main() {
	//Declare Variables
	string again = "yes";
	double MortData, MortInfo;


	Header();
	do {
		AskForLoanInfo(MortInfo, MortData);

		if (Validate(MortInfo, MortData) == false) {
			cout << "Your input was out of the range, please re-run the program "
				<< "\nwithin the appropriate ranges.";
		}
		else {
			MortCalc(MortInfo, MortData);
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


void AskForLoanInfo(double MortInfo, double &MortData) {

	float interest;
	int principal, term;
	mortInfo info;
	cout << "\n What is the ammount of the loan in whole dollars? ";
	cin >> info.principal;

	cout << "\n Is the term 15, 25, or 30 years? ";
	cin >> info.term;

	cout << "\n What is the interest rate? (enter 5, for 5\%, 3.5 for 2.5\% ";
	cin >> info.interest;
	cout << "\n " << info.principal;

}

bool Validate(double MortInfo, double &MortData) {
	mortInfo info;
	if (info.principal < 500000 && info.principal > 0 && info.term == 15 || info.term == 25
			|| info.term == 30 && info.interest > 0 && info.interest <= 10) {
		return true;
	}
	else {
		return true;
	}
}

void CalcEndOfLoan(double MortInfo, double &MortData) {
	mortInfo info;
	tm *currentTime;
	time_t t = time(NULL);

	int currentYear = 1900 + currentTime->tm_year;
	int currentMonth = currentTime->tm_mon;
	int currentDay = currentTime->tm_mday;
	int endYear = currentYear + info.term;

	cout << "\n Loan maturity date " << currentMonth << "/" << currentDay << "/" << endYear;


}


////////////////////////////////
//NOT FINISHED. RE-WRITE THIS MESS
////////////////////////////////
bool WriteMort(string result, string filename) {
	static int counter = 0;
	counter++;
	stringstream ss;
	ss << name << counter << ".txt";
	Date = myDate;

	string sDate = myDAte.GetFromattedDAte809
	string name;
	cout << "\n What do you want to name the file? ";
	getline(cin,name);

	// declare the output file object
	ofstream outputFile;

	// Open the file for writing
	outputFile.open(name);

	// Check that we've open the file
	if (!outputFile)
	{
		cout << "\n The file was not written ";
		return false;
	}

	// Write to the file
	outputFile << loanInfo << endl;


	// close the file
	outputFile.close();
	cout << "\n The file was written. ";
	return true;
}

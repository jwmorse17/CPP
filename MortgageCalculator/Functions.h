  //Joshua Morse jmorse2@cnm.edu
//MorseP6
//File: Functions.h

#include <iostream>
using namespace std;


//function prototypes
void Header();
void AskForLoanInfo(double MortInfo, double &MortData);
bool Validate(double MortInfo, double &MortData);
string MortCalc(double MortInfo, double &MortData);
bool WriteMort(string result, string filename);
void CalcEndOfLoan(double MortInfo, double &MortData);


struct mortInfo {
	float interest;
	int principal;
	int term;

	//start date of loan
	int monStart, dayStart, yearStart;
	//end date of loan
	int monEnd, dayEnd, yearEnd;
};

//Joshua Morse jmorse2@cnm.edu
//MorseP6
//File: Functions.h

#include <iostream>
#include "MortInfo.h"
using namespace std;

//function prototypes
void Header();
void AskForLoanInfo(MortInfo &mortData);
bool Validate(MortInfo &mortData);
string MortCalc(MortInfo &mortData);
bool WriteMort(string result, string filename);
void CalcEndOfLoan(MortInfo &mortData);





//Joshua Morse jmorse2@cnm.edu
//MorseP6
//File: MortCalc.h

#include <iostream>
#include <string>
#include <cmath>
#include "Functions.h"

using namespace std;


string MortCalc(double MortInfo, double &MortData) {
	mortInfo info;
	double monthlyPayment = (info.principal * info.interest) / (12 * (1 - (pow(1 + info.interest / 12), -(info.term * 12))));
	double totalLoan = (monthlyPayment * 12) * info.term;
	double totalInterest = totalLoan - info.principal;

	CalcEndOfLoan(MortInfo, MortData);

}

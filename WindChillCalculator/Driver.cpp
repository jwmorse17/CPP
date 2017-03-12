#include <iostream>
#include <string>
#include <cmath> //for pow()

using namespace std;

//declare variables
double AskForTemperature();
double AskForWindSpeed();
int ValidateTempWS(double temp, double windsp);
double CalcWindChill(double temp, double windsp);
int DetermineFrostbitetimes(double temp, double windsp);

int main() {

	double temp, windsp, windChill;
	int frostbiteTime, validate;
	string answer = "yes"; //used to see if user will run program again.

	cout << "\n Joshua Morse Program 4"
		<< "\n File: Driver.cpp. "
		<< "\n\n this program is going to find the wind chill and time\n to frostbite based off user input for wind speed and temperature.";

	do {

		// get user input
		temp = AskForTemperature();
		windsp = AskForWindSpeed();
		validate = ValidateTempWS(temp, windsp); //check to see if user input is within spec

		if (validate == 0) {//within spec

			windChill = CalcWindChill(temp, windsp);
			frostbiteTime = DetermineFrostbitetimes(temp, windsp);

			cout << "\n frostbiteTime " << frostbiteTime; // using this to test output of frostbitetime

			cout.precision(2);
			cout << "\n\n The current temperature is " << temp << " degrees fahrenheit."
				<< "\n The wind is blowing at " << windsp << " MPH."
				<< "\n It feels like " << windChill << " degrees right now. ";

			if (frostbiteTime > 0) {
				cout << "\n Exposed skin can experience frostbite in " << frostbiteTime << " minutes";
			}
			else {
				cout << "\n You are in no immediate danger.";
			}
		}
		else if (validate == 1) { //wind too slow
			cout << "\n\n The temperature you chose is " << temp << "\n which is below 40 degree, "
				<< "\n but the wind speed " << windsp << " is below 5 mph so we cannot perform the calculation.";
			break;
		}
		else if (validate == 2) { //temp to high
			cout << "\n\n The wind speed " << windsp << " is above 5 mph, "
				<< "\n but the temperature " << temp << " is above 40 so we cannot perform the calculation.";
			break;
		}
		else if (validate == 3) { //temp to high, wind too slow
			cout << "\n\n The wind speed " << windsp << " is below 5 mph, "
				<< "\n and the temperature " << temp << " is aboce 40, so we cannot perform the calculation. ";
			break;
		}

		cout << "\n Would you like to check another temp/windspeed combination? (yes/no) ==> ";
		getline(cin, answer);

	} while (answer == "yes");

	cout << "\n\n Thank you for using this program, goodbye" << endl;
}

double AskForTemperature() {
	double temp;
	cout << "\n Enter a temperature at or below 40 degrees fahrenheit ==> ";
	cin >> temp;
	cin.ignore();
	return temp;
}

double AskForWindSpeed() {
	double wind;
	cout << "\n Enter a windspeed at or above 5 MPH ==> ";
	cin >> wind;
	cin.ignore();
	return wind;
}

int ValidateTempWS(double temp, double windsp) {
	if (temp <= 40 && windsp >= 5) {
		return 0; // input is within rage
	}
	else if (temp <= 40 && windsp < 5) {
		return 1; //wind is too slow
	}
	else if (temp > 40 && windsp >= 5) {
		return 2; // temp is too high
	}
	else {
		return 3; //wind and temp are too slow and high respectively.
	}
}

double CalcWindChill(double temp, double windsp) {
	double windChill = 35.74 + (0.6215 * temp) - (35.75 * pow(windsp, 0.16)) + ((0.4275 * temp) * pow(windsp, 0.16));
	return windChill;
}

int DetermineFrostbitetimes(double temp, double windsp) {
	double frostbiteTime = (-24.5 * ((0.667 * (windsp * 1.6) + 4.8)) + 2111) * pow((-4.8 - ((temp - 32) * 0.555)), -1.668);
	cout << "\n frostbiteTime func " << frostbiteTime; // using this to test output of frostbitetime

	return frostbiteTime;

}

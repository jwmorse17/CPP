/* Copyright (c) 2016> Joshua Morse
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files
(the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify,
merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

//Joshua Morse, Driver.cpp

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//make definitions
#define PI 3.14159265
#define gallonsToInches 231

int main()
{
	cout << "\n\n Joshua Morse \n Calculating a Lune \n This program asks the user which planet's Lune"
		<< "they would like to calculate \n then prints that result to the screen\n\n";

	string userName, answer, planetChoice;
	double percentIlluminated = 0.0, wedge = 0.0, luneSurfaceArea = 0.0, diameter = 0.0, surfaceKMCubed = 0.0, surfaceINCubed = 0.0;
	double  convertedPercentIlluminated = 0.0;
	int index = 0;

	//declare vectors
	vector<string> planet;
	vector<double> radius;


	//add values to vectors
	planet.push_back("Mercury");
	planet.push_back("Mars");
	planet.push_back("Venus");
	planet.push_back("Saturn");
	planet.push_back("Jupiter");
	planet.push_back("Moon");

	radius.push_back(2240);
	radius.push_back(3397);
	radius.push_back(6052);
	radius.push_back(60268);
	radius.push_back(71492);
	radius.push_back(1738);

	do
	{
		bool didNotFindIt = true;

		//take user input
		cout << "\n What is your name? ";
		getline(cin, userName);

		cout << "\n\n Hello " << userName << ", which of the folloiwng planets would you like to calculate the lune of?"
			<< "\n Mercury \n Mars \n Venus \n Saturn \n Jupiter \n Moon"
			<< "\n ==> ";
		getline(cin, planetChoice);

		cout << "\n\n What percent is " << planetChoice << "Illuminated? (0 - 100) ";
		cin >> percentIlluminated;

		//verify percentIlluminated is between 0 and 100 so final calculatins are accurate.
		if (percentIlluminated < 0 || percentIlluminated > 100)
		{
			cout << "You are not in range, re-run the program and enter a percent illuminated between 0 and 100 \n";
			break;
		}
		else
		{


			while (didNotFindIt == true)
			{
				if (planetChoice == planet.at(index))
				{


					//Perform calculations
					convertedPercentIlluminated = percentIlluminated / 100; //convert to decimal place. i.e. input of 50 is .5

					diameter = radius.at(index) * radius.at(index); //convert radius to diameter
					wedge = convertedPercentIlluminated * PI;
					luneSurfaceArea = (2 * diameter) * wedge; //formula: S = 2 * r^2 * wedge

															//conversions
					surfaceKMCubed = luneSurfaceArea / 3; //convert surface area to KM cubed
					surfaceINCubed = surfaceKMCubed / 0.000000000000016387064; //convert KM cubed to IN cubed


					//set precision
					cout.setf(ios::fixed, ios::floatfield);
					cout.precision(3);


					//output results to user
					cout << "\n\n " << userName << ","
						<< "\n You chose the " << planet.at(index) << " Which has a radius of " << radius.at(index)
						<< "\n at " << percentIlluminated << "% illlumination"
						<< " The surface area of the lune is " << luneSurfaceArea << "\n";


					didNotFindIt = false;
				}
				else
				{
					++index;
				}
			}
		}

		cout << "\n\n Do you want to run the program again? yes/no ==> ";
		getline(cin, answer);

	}while (answer == "yes");

	return 0;
}

// Joshua Morse
//File: Driver.cpp

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	//declare an initialize my count variables

	int i = 0, counter = 1000, winChangeCounter = 0, winFirstCounter = 0, loseCounter = 0, changeCounter = 0, hostChoice = 0, remainingDoor = 0, elsecounter = 0;


	//write header
	cout << "\n This program attemps to solve the Monty Hall problem. There are three doors. behind one is a car, behind the other"
		<< "\n two are goats. After the contestant chooses a door the host will reveal which one of the doors you did not choose has"
		<< "\n the goat. Is it to your advantage to change doors or stick with the origional choice? This program will simulate 1000"
		<< "\n games to determine the answer. \n\n";

	for (i; i < counter; ++i) // counter is set to 1000 so for will loop 1000 times
	{

		int prizeDoor = (1 + rand() % 3);

		// 0 = goat, 1 = car
		int doorOne = 0;
		int doorTwo = 0;
		int doorThree = 0;



		//fill prize door with car
		if (prizeDoor == 1)
		{
			doorOne = 1;
		}
		else if (prizeDoor == 2)
		{
			doorTwo = 1;
		}
		else
		{
			doorThree = 1;
		}

		//contestant picks a door
		int firstChoice = (1 + rand() % 3);


		//host picks a door that is not the one with the car or the one the contestant chose
		for (int j = 1; j <= 3; j++)
		{
			if (j != firstChoice && j != prizeDoor)
			{
				hostChoice = j;
				break;
			}
		}

		//check and see if the first choice won
		for (int k = 1; k <= 3; k++)
		{
			if (k == prizeDoor && k == firstChoice)
			{
				++winFirstCounter;
			}
			//determin if switching will result in win
			else if (k == prizeDoor && k != firstChoice)
			{
				++winChangeCounter;
			}
		}
	}

	//perform calculations for final output
	int totalLost = counter - winFirstCounter - winChangeCounter;
	int totalWon = winFirstCounter + winChangeCounter;
	int percentWonFirst = winFirstCounter * 100 / totalWon;
	int percentWonChange = winChangeCounter * 100 / totalWon;


	//output results
	cout << "\n Out of 1000 games: "
		<< "\n " << elsecounter << " else "
		<< "\n " << winFirstCounter << " were won without changing."
		<< "\n " << winChangeCounter << " were won with changeing the door first chosen."
		<< "\n " << percentWonFirst << "% won without changing doors."
		<< "\n " << percentWonChange << "% won by changing doors.\n";

	return 0;
}

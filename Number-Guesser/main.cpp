#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "binarysearch.h"
using std::cout;
using std::endl;
using std::cin;
using namespace std::chrono_literals;
using namespace std::this_thread;

int main()
{
	int input = 0; // player's input
	int guess = 0; // computer's guess
	int oldGuess = 0; // computer's previous guess
	int min = 1; // minimum value for binary search
	int max = 100; // maximum value for binary search
	int counter = 0; // tracks number of guesses
	bool win = false; // tracks win condition

	cout << "Think of a number for me to guess." << endl;
	cout << "Press enter to continue";
	getchar();
	ClearScreen();
	// Game loop
	while (!win)
	{
		// make the computer guess a number
		guess = findMidPoint(min, max);
		// if it's impossible for it to be any other number, do this
		if (guess == oldGuess)
		{
			cout << "\nI don't think it's anything else but " << guess << "!" << endl;
			sleep_for(2s);
			return 0;
		}
		// set old guess to current guess
		oldGuess = guess;
		cout << "The number I'm thinking about is " << guess << endl;
		cout << "\nIs the number higher, lower, or correct?" << endl;
		cout << R"(1. Higher
2. Lower
3. Correct)" << endl;
		// ask for player input
		cin >> input;
		// increase number of guesses
		counter++;
		// decide what to do depending on player's input
		switch (input)
		{
		case 1:
			// set lower-bound to computer's guess
			min = guess;
			break;
		case 2:
			// set upper-bound to computer's guess
			max = guess;
			break;
		case 3:
			// computer made a correct guess
			cout << "\nYay! I got it right! ^_^" << endl;
			if (counter == 1)
			{
				cout << "It took me 1 guess." << endl;
			}
			else
			{
				cout << "It took me " << counter << " guesses." << endl;
			}
			win = true;
			sleep_for(1s);
			break;
		default:
			break;
		}
	}
}
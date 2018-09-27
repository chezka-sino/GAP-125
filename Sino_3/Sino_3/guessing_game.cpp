/*
guessing_game.cpp : HW 3
Interactive program that lets user guess a random number generated within the specified range
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void main()
{
	int min, max, guess;

	// For debugging purposes only
	// srand(44);
	srand(time(NULL));

	cout << "Please enter the mininum number: ";
	cin >> min;
	cout << "Please enter the maximum number: ";
	cin >> max;

	// Quits program if user inputs invalid range
	if (max <= min)
	{
		cout << "Invalid range";
	}

	else
	{
		int out = (rand() % (max - min)) + min;

		// For debugging purposes only
		// cout << "The random number is: " << out << "\n";

		cout << "Guess the number: ";
		cin >> guess;

		if (guess != out)
		{
			cout << "Incorrect! The correct number is " << out << ".\n";
			cout << "Your guess is off by " << abs(guess-out);
		}

		else
		{
			cout << "Correct!";
		}

	}
}
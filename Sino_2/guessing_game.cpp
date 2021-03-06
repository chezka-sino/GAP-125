// guessing_game.cpp : HW 2
// Interactive program which computes the average of three numbers inputted by user

#include <iostream>
using namespace std;

void main() {
	float sum = 0;
	float num, aveGuess;
	char guess;

	// Asks user to input three numbers
	cout << "Please enter three numbers:\n";
	for (int i = 0; i < 3; i++) {
		cin >> num;
		// Asks the user to input a valid number
		while (cin.fail()) {
			cout << "Please enter a valid number" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> num;
		}
		sum += num;
	}

	float average = sum / 3;

	// Asks if user would like to guess the average of the entered numbers
	cout << "Would you like to guess the average?";
	cin >> guess;

	if (guess == 'y' | guess == 'Y') {
		cout << "Enter your guess: ";
		cin >> aveGuess;
		if (aveGuess == average) {
			cout << "Correct!\n";
		}
		else {
			cout << "That is incorrect.\n";
		}
	}
	
	cout << "The average of the numbers is " << average;

}
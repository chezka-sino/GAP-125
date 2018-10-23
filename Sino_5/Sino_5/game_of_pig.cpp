/*
	GAP 125 HW 5: Game of Pig
	Chezka Sino
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;

void PrintRules()
{
	cout << "Rules:\n";
	cout << "During each turn, the player chooses:\n";
	cout << "\t roll:\n";
	cout << "\t\t If the player rolls a 1, their turn ends and they earn a score of zero for the turn.\n";
	cout << "\t\t If the player rolls 2 through 6, the number is added to the player's turn total and the player's turn continues.\n";
	cout << "\t\t The player can keep rolling as long as it is still their turn.\n";
	cout << "\t bank:\n";
	cout << "\t\t The turn's total score is added to the player's total score. Then their turn ends.\n\n";

	cout << "The first player to reach 100 wins the game.\n\n";

}

void PrintRoll(int player, int roll, int score)
{
	cout << "Player " << player << " rolled a " << roll << "\n";
	cout << "Player " << player << "'s current score is " << score << "\n";
}

int Roll()
{
	return (rand() % 6) + 1;
}

int SwitchTurn(int i)
{
	if (i == 1) {
		i = 2;
	}

	return 1;

}

string Move(int i)
{
	string move;

	cout << "Player " << i << "> ";
	cin >> move;

	return move;

}

int First()
{
	return (rand() % 2) + 1;
}

void PrintFirst(int i)
{

	cout << "Player " << i << " goes first.\n";
}

void main()
{
	int playerOne = 0;
	int playerTwo = 0;

	srand(44);
	//srand(time(NULL));

	cout << "Welcome to the Game of Pig!\n";

	PrintRules();

	int turn = First();
	PrintFirst(turn);
	
	while (playerOne < 100 && playerTwo < 100) {

		string move = Move(turn);

		if (move == "roll")
		{
			int diceRoll = Roll();

			if (diceRoll == 1)
			{
				turn = SwitchTurn(turn);
			}
			else
			{
				if (turn == 1)
				{
					playerOne += diceRoll;
					PrintRoll(turn, diceRoll, playerOne);
				}
				else if (turn == 2)
				{
					playerTwo += diceRoll;
					PrintRoll(turn, diceRoll, playerTwo);
				}
			}
		}

		else if (move == "bank")
		{
			turn = SwitchTurn(turn);
			cout << "It is now Player " << turn << "'s turn to play\n";
		}

	}

	cout << "Player " << turn << " wins!!!";

}
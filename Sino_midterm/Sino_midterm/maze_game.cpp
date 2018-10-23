/*
	Midterm Project: Maze
	Chezka Sino
*/

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

const int k_MazeWidth = 42;
const int k_MazeHeight = 42;

int playerX = 1;
int playerY = 1;
int finX = 39;
int finY = 39;
int stepCount = 0;

char maze[k_MazeWidth][k_MazeHeight]
{
	{ "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" },
	{ "| |     |   |   |   |         |       | |" },
	{ "+ +-+-+ +-+ + + + + +-+-+-+ + + +-+-+ +-+" },
	{ "|   |     |   |   |         |   |   | | |" },
	{ "+-+ + + + + +-+-+-+-+-+-+-+-+-+-+-+ + + +" },
	{ "|   | | | | |           |     |       | |" },
	{ "+ +-+ +-+ + + +-+-+-+-+ + +-+ + +-+-+ + +" },
	{ "| |     |   | |     | | | | |   |   |   |" },
	{ "+ + +-+ + +-+ +-+ + + + + + +-+-+ +-+-+-+" },
	{ "|   |   |   |   | |     |             | |" },
	{ "+-+-+ +-+-+-+-+ +-+-+ +-+-+ +-+-+ +-+ + +" },
	{ "|   |   |       |   |     | |   |   | | |" },
	{ "+ + +-+ + +-+-+-+ + +-+ + +-+ + +-+ + + +" },
	{ "| |     |   |     | |   |   | |     | | |" },
	{ "+ +-+-+-+-+ + +-+-+ + +-+-+ + +-+-+-+ + +" },
	{ "|       |   | |   | | |   |   |     |   |" },
	{ "+-+ +-+-+ +-+ + + + +-+ + +-+ +-+-+ +-+ +" },
	{ "|   |   |   |   | | |   |   | |     | | |" },
	{ "+ +-+ + +-+ +-+ + + + +-+-+ + + + +-+ + +" },
	{ "|   | |   |   | | |   |   | | | | | | | |" },
	{ "+-+ +-+ + +-+ +-+ + +-+ +-+ +-+ + + + + +" },
	{ "|   |   |   |   | |   | |       |   |   |" },
	{ "+ +-+ +-+-+-+-+ + + + + + + +-+-+-+-+-+-+" },
	{ "| |   | |     | | | | |   | |       |   |" },
	{ "+ + +-+ + +-+ + + + + + +-+ + +-+-+ + +-+" },
	{ "| | |   |   |     | | | |   |     | |   |" },
	{ "+ + + + +-+ +-+-+-+-+ +-+ +-+-+-+-+ +-+ +" },
	{ "| | | |     |   |   | |   |       | |   |" },
	{ "+ + + +-+-+-+ +-+ + + + + + +-+-+ + + +-+" },
	{ "|   |       |     |   | |       |   |   |" },
	{ "+-+ +-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+ +" },
	{ "|   |   | |     |         |       |   | |" },
	{ "+ +-+ + + + +-+ +-+ +-+-+ + +-+-+ +-+ + +" },
	{ "| | | |     | |     | |   | |   |   |   |" },
	{ "+ + + +-+-+-+ +-+-+-+ + +-+ +-+ +-+ + + +" },
	{ "|   | |   |     |   |   |     | | |   | |" },
	{ "+ +-+ + +-+ +-+ +-+ +-+-+-+ + + + +-+-+ +" },
	{ "| |   |     |   |   |   |   | | |     | |" },
	{ "+ + +-+ +-+-+ +-+ + + + + +-+ + + +-+ + +" },
	{ "| |         |     |   |     |   |   |   |" },
	{ "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" }
};

void PrintMaze(char maze[k_MazeWidth][k_MazeHeight])
{
	for (int i = 0; i < k_MazeHeight; i++)
	{
		for (int j = 0; j < k_MazeWidth; j++)
		{
			cout << maze[i][j];
		}
		
		cout << "\n";
	}
}

void PrintIns()
{
	cout << "Welcome to the Maze!\n\n";
	cout << "The goal is to make it to the exit point\n";
	cout << "Controls: Enter 'up', 'down', 'left' or 'right' to navigate.\n\n";
}

bool CheckUp(int y, int x)
{
	if (maze[y-1][x] == ' ')
	{
		stepCount++;
		return true;
	}

	return false;
}

bool CheckDown(int y, int x)
{
	if (maze[y+1][x] == ' ')
	{
		stepCount++;
		return true;
	}

	return false;
}

bool CheckLeft(int y, int x)
{
	if (maze[y][x-1] == ' ')
	{
		stepCount++;
		return true;
	}

	return false;
}

bool CheckRight(int y, int x)
{
	if (maze[y][x+1] == ' ')
	{
		stepCount++;
		return true;
	}

	return false;
}

void MoveUp()
{
	playerY = playerY-2;
}

void MoveDown()
{
	playerY = playerY+2;
}

void MoveLeft()
{
	playerX = playerX-2;
}

void MoveRight()
{
	playerX = playerX+2;
}

void main()
{
	// Initialize starting and end point
	maze[playerY][playerX] = '@';
	maze[finX][finY] = 'X';

	PrintIns();
	PrintMaze(maze);

	string move;

	while (playerX != finX && playerY != finY)
	{
		maze[playerY][playerX] = ' ';
		cout << "Move: ";
		cin >> move;
		cout << "\n";

		if (move == "up")
		{
			if (CheckUp(playerY, playerX))
			{
				MoveUp();
			}
			else
			{
				cout << "Unable to move up\n";
			}
		}

		else if (move == "down")
		{
			if (CheckDown(playerY, playerX))
			{
				MoveDown();
			}
			else
			{
				cout << "Unable to move down\n";
			}
		}

		else if (move == "left")
		{
			if (CheckLeft(playerY, playerX))
			{
				MoveLeft();
			}
			else
			{
				cout << "Unable to move to the left\n";
			}
		}

		else if (move == "right")
		{
			if (CheckRight(playerY, playerX))
			{
				MoveRight();
			}
			else
			{
				cout << "Unable to move to the right\n";
			}
		}

		maze[playerY][playerX] = '@';
		PrintMaze(maze);
		//play the game

	}

}
/*
	Midterm Project: Maze
	Chezka Sino
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
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
	cout << "Controls: w - up; a - left; s - down; d - right\n\n";
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

void EndGame()
{
	cout << "Congratulations!\n";
	cout << "You finished the maze after " << stepCount << " steps.";
}

void main()
{
	// Initialize starting and end point
	maze[playerY][playerX] = '@';
	maze[finX][finY] = 'X';

	PrintIns();
	PrintMaze(maze);

	char move = 0;

	while (playerX != finX && playerY != finY)
	{
		maze[playerY][playerX] = ' ';
		cout << "Move: ";
		move = _getch();
		cout << "\n";

		switch (move)
		{
			case 'w':
				if (CheckUp(playerY, playerX))
				{
					MoveUp();
				}
				else
				{
					cout << "Unable to move up\n";
				}
				break;
			case 's':
				if (CheckDown(playerY, playerX))
				{
					MoveDown();
				}
				else
				{
					cout << "Unable to move down\n";
				}
				break;
			case 'a':
				if (CheckLeft(playerY, playerX))
				{
					MoveLeft();
				}
				else
				{
					cout << "Unable to move to the left\n";
				}
				break;
			case 'd':
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
	}
	EndGame();
}
/*
	GAP 125 HW 4: Vending Machine
	Chezka Sino
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*
	Prints the exit function with the price of the chosen item or 0 if exit is chosen
*/
void print_price(double price)
{
	cout << "Thank you! Your total is $" << price;
}

/*
	Contains prices of the items and passes price to print_price to print price
*/
void price(int category, int item)
{
	if (category == 1)
	{
		if (item == 1 || item == 2 || item == 3)
		{
			print_price(3.50);
		}
		else if (item == 4)
		{
			print_price(1.99);
		}
		else if (item == 5)
		{
			print_price(0.99);
		}
	}
	else if (category == 2)
	{
		if (item == 1 || item == 3 || item == 5)
		{
			print_price(1.99);
		}
		else if (item == 2 || item == 4)
		{
			print_price(3.99);
		}
	}
	else if (category == 3)
	{
		if (item == 1 || item == 2 || item == 4 || item == 5)
		{
			print_price(0.99);
		}
		else if (item == 3)
			print_price(1.99);
	}
	else if (category == 4)
	{
		print_price(0.99);
	}

}

/*
	Prints the menu for each category and passes category to price to get item price
*/
void menu(int category)
{
	int item;

	if (category == 1)
	{
		cout << "Beverages:\n";
		cout << "1. Americano \t\t $3.50\n";
		cout << "2. Iced Coffee \t\t $3.50\n";
		cout << "3. Iced Tea \t\t $3.50\n";
		cout << "4. Bottled Water \t $1.99\n";
		cout << "5. Fountain Drink \t $0.99\n";
		cout << "Choose a drink: ";

	}

	else if (category == 2)
	{
		cout << "Baked Goods:\n";
		cout << "1. Chocolate Chip Cookie \t $1.99\n";
		cout << "2. Strawberry Cheesecake \t $3.99\n";
		cout << "3. Butter Croissant \t\t $1.99\n";
		cout << "4. Red Velvet Cupcake \t\t $3.99\n";
		cout << "5. Blueberry Scone \t\t $1.99\n";
		cout << "Choose one: ";
	}

	else if (category == 3)
	{
		cout << "Fruits:\n";
		cout << "1. Apple \t $0.99\n";
		cout << "2. Banana \t $0.99\n";
		cout << "3. Avocado \t $1.99\n";
		cout << "4. Orange \t $0.99\n";
		cout << "5. Mango \t $0.99\n";
		cout << "Choose a fruit: ";
	}

	else if (category == 4)
	{
		cout << "Candy:\n";
		cout << "1. Peppermint Candy \t $0.99\n";
		cout << "2. Dark Chocolate Bar \t $0.99\n";
		cout << "3. Milk Chocolate Bar \t $0.99\n";
		cout << "4. Gummy Worms \t\t $0.99\n";
		cout << "5. Jelly Beans \t\t $0.99\n";
		cout << "Choose a candy: ";
	}

	cin >> item;
	cout << "\n";
	price(category,item);

}

void main()
{
	int choice;

	cout << "Welcome!!!\n";
	cout << "Main Menu:\n";
	cout << "1. Beverages\n";
	cout << "2. Baked Goods\n";
	cout << "3. Fruits\n";
	cout << "4. Candy\n";
	cout << "5. Exit\n";
	cout << "Choose a category: ";
	cin >> choice;
	cout << "\n";

	if (choice == 5)
	{
		print_price(0);
	}

	else
	{
		menu(choice);
	}

}
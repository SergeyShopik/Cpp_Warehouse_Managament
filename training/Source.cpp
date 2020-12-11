#include<iostream>
#include<cctype>
#include<cstring>
#include<cstdlib>
const int SIZE = 100;
//warehouse managament
struct inv_type
{
	char item[40];
	double cost, retail;
	int on_hand, lead_time;
} invtry[SIZE];
void init_list();
int menu();
void input(int);
void enter();
void update();
void display();
void find();
void showFound(int);

int main()
{
	int n = 0;
	//warehouse managament
	char choice;
	init_list();
	for  ( ; ; )
	{
		choice = menu();
		switch (choice)
		{
		case 'e': enter();
			break;
		case 'd': display();
			break;
		case 'u': update();
			break;
		case 'f': find();
			break;
		case 's': showFound(n);
			break;
		case 'q': return 0;
		}
	}

	system("pause");
	return 0;
}

void init_list()
{
	for (int i = 0; i < SIZE; i++) *invtry[i].item = '\0';
}
int menu()
{
	char ch;
	std::cout << '\n';
	do
	{
		std::cout << "(E)nter\n";
		std::cout << "(D)isplay\n";
		std::cout << "(U)pdate\n";
		std::cout << "(F)ind\n";
		std::cout << "(S)how\n";
		std::cout << "(Q)uit\n\n";
		std::cout << "Choose comand: ";
		std::cin >> ch;
	} while (!strchr("edufsq", tolower(ch)));
	return tolower(ch);
}
void input(int i)
{
	std::cout << "Good: ";
	std::cin >> invtry[i].item;

	std::cout << "Cost: ";
	std::cin >> invtry[i].cost;

	std::cout << "Price: ";
	std::cin >> invtry[i].retail;

	std::cout << "Stock: ";
	std::cin >> invtry[i].on_hand;
	
	std::cout << "Lead time: ";
	std::cin >> invtry[i].lead_time;
}
void enter()
{
	int i;
	for (i = 0; i < SIZE; i++)
		if (!*invtry[i].item) break;

	if (i == SIZE)
	{
		std::cout << "List is full.\n";
		return;
	}
	input(i);
}
void update()
{
	int i;
	char name[80];

	std::cout << "Enter good's name: ";
	std::cin >> name;
	for (i = 0; i < SIZE; i++)
		if (!strcmp(name, invtry[i].item)) break;

	if (i == SIZE)
	{
		std::wcout << "Good is not found.\n";
		return;
	}
	std::cout << "Enter new info.\n";
	input(i);
}
void display()
{
	int i;
	for (i = 0; i < SIZE; i++)
	{
		if (*invtry[i].item)
		{
			std::cout << invtry[i].item << '\n';
			std::cout << "Cost: $" << invtry[i].cost;
			std::cout << "\nPrice: $";
			std::cout << invtry[i].retail;
			std::cout << "\nStock: " << invtry[i].on_hand;
			std::cout << "\nLead time remaining: ";
			std::cout << invtry[i].lead_time << " days\n\n";
		}
	}
}
void find()
{
	int i;
	char name[80];

	std::cout << "Enter good's name: ";
	std::cin >> name;
	for (i = 0; i < SIZE; i++)
		if (!strcmp(name, invtry[i].item)) break;

	if (i == SIZE)
	{
		std::cout << "Good is not found.\n";
		return;
	}
	std::cout << "Enter new info.\n";
	showFound(i);
}
void showFound(int i)
{
	for (i = 0; i < SIZE; i++)
	{
		if (*invtry[i].item)
		{
			std::cout << invtry[i].item << '\n';
			std::cout << "Cost: $" << invtry[i].cost;
			std::cout << "\nPrice: $";
			std::cout << invtry[i].retail;
			std::cout << "\nStock: " << invtry[i].on_hand;
			std::cout << "\nLead time remaining: ";
			std::cout << invtry[i].lead_time << " days\n\n";
		}
	}
}

#include "array.hpp"
#include <iostream>
#include <regex>

static bool isValidName(std::string name)
{
	std::regex regName("^[A-Z][a-z]+\\s[A-Z][a-z]+$");
	return std::regex_match(name, regName);
}

static bool isValidTele(std::string tele)
{
	std::regex regTele("^[0-9]{11}$");
	return std::regex_match(tele, regTele);
}

static bool isValidDate(std::string date)
{
	std::regex regDate("^(0[1-9]|[1-2][0-9]|3[0-1])\\.(0[1-9]|1[0-2])\\.(19|20)\\d{2}$");
	return std::regex_match(date, regDate);
}

static void PrintText(std::string text)
{
	if (text != ">>") std::cout << text << std::endl;
	else std::cout << text + " ";
}

static void Print(Array* ar, unsigned int i)
{
	if (i == -1) PrintText("The man is not find");
	else std::cout << ar->getNOTE2(i)->getName() << " " \
		<< ar->getNOTE2(i)->getTELE() << " " \
		<< ar->getNOTE2(i)->getDATE() << std::endl;
}

static void PrintAll(Array* ar)
{
	for (unsigned int i = 0; i < ar->getLenght(); i++)
	{
		Print(ar, i);
	}
}

static void InputArray(Array* ar, size_t lenght)
{
	for (unsigned int i = 0; i < lenght; i++)
	{
		PrintText("-------------------------");
		PrintText("Enter first and last name separated by a space");
		PrintText(">>");
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::string name;
		while (true)
		{
			std::getline(std::cin, name);
			if (isValidName(name)) break;
			else
			{
				PrintText("The name or surname is incorrect. Enter again");
				PrintText(">>");
			}
		}

		PrintText("Enter the phone number");
		PrintText(">>");
		std::string tele;
		while (true)
		{
			std::cin >> tele;
			if (isValidTele(tele)) break;
			else
			{
				PrintText("The phone number is incorrect. Enter again");
				PrintText(">>");
			}	
		}

		PrintText("Enter the date of birth");
		PrintText(">>");
		std::string date;
		while (true)
		{
			std::cin >> date;
			if (isValidDate(date)) break;
			else 
			{
				PrintText("The date of birth is incorrect. Enter again");
				PrintText(">>");
			} 
		}

		ar->setNOTE2(name, tele, date, i);
	}
}

int main()
{
	system("color F1");
	PrintText("Welcome to the array's program!");
	PrintText("Enter the size of the array");
	PrintText(">>");
	int tempLenght;
	while (!(std::cin >> tempLenght) || tempLenght < 1)
	{
		PrintText("The size of array is incorrect. Enter again");
		PrintText(">>");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	size_t lenght = static_cast<size_t>(tempLenght);
	std::cout << lenght << std::endl;

	Array* BLOCK2 = new Array(lenght);
	InputArray(BLOCK2, lenght);
	system("pause");
	system("cls");
	PrintText("You enter");
	PrintAll(BLOCK2);
	system("pause");
	system("cls");
	BLOCK2->setSorted();
	PrintText("Sorted array");
	PrintAll(BLOCK2);
	system("pause");
	system("cls");
	
	PrintText("Enter the surname of man");
	PrintText(">>");
	std::string surname;
	std::cin >> surname;
	Print(BLOCK2, BLOCK2->HasInArray(surname));

	delete BLOCK2;
	return 0;
}
 
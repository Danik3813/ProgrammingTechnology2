#include "array.hpp"
#include <iostream>

static void PrintText(std::string text)
{
	if (text != ">>") std::cout << text << std::endl;
	else std::cout << text + " ";
}

static void Print(Array* ar, unsigned int i)
{
	if (i == -1) PrintText("������ ������� �� ������!");
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

int main()
{
	setlocale(LC_ALL, "ru");
	PrintText("������� ������ �������");
	PrintText(">>");
	size_t lenght;
	std::cin >> lenght;
	Array* BLOCK2 = new Array(lenght);

	for (unsigned int i = 0; i < lenght; i++)
	{
		PrintText("������� ��� � ������� ����� ������");
		PrintText(">>");
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::string name;
		std::getline(std::cin, name);
		PrintText("������� ����� ��������");
		PrintText(">>");
		std::string tele;
		std::cin >> tele;
		PrintText("������� ���� ��������");
		PrintText(">>");
		std::string date;
		std::cin >> date;
		BLOCK2->setNOTE2(name, tele, date, i);
	}
	
	PrintText("������� ������� ��������!");
	PrintText(">>");
	std::string surname;
	std::cin >> surname;
	Print(BLOCK2, BLOCK2->HasInArray(surname));
	delete BLOCK2;
	return 0;
}

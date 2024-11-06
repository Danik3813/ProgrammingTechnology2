#include "array.hpp"

Array::Array(size_t lenght)
{
	this->lenght = lenght;
	arr = new NOTE2[lenght];
}

void Array::setSorted()
{
	for (unsigned k = 0; k < 3; k++)
	{
		for (unsigned int j = 1; j < lenght; j++)
		{
			bool isSorted = true;
			for (int i = 0; i < lenght - j; i++)
			{
				if (arr[i].getTELE() > arr[i + 1].getTELE())
				{
					NOTE2 temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
					isSorted = false;
				}
			}
			if (isSorted) break;
		}
	}
}

NOTE2* Array::getNOTE2(unsigned int i)
{
	return (arr + i);
}

void Array::setNOTE2(std::string Name, std::string TELE, std::string DATE, unsigned int i)
{
	(arr + i)->setName(Name);
	(arr + i)->setTELE(TELE);
	(arr + i)->setDATE(DATE);
}

size_t Array::getLenght() const
{
	return lenght;
}

int Array::HasInArray(std::string surname) const
{
	for (unsigned int i = 0; i < lenght; i++)
	{
		std::stringstream streamName(arr[i].getName());
		std::string _name, _surname;
		std::getline(streamName, _name, ' ');
		std::getline(streamName, _surname, ' ');
		if (surname == _surname) return i;
	}
	return -1;
}


#include "array.hpp"

Array::Array(size_t lenght)
{
	this->lenght = lenght;
	arr = new NOTE2[lenght];
}

void Array::setSorted()
{
	for (unsigned int k = 0; k < 3; k++)
	{
		for (unsigned int i = 0; i < lenght; i++)
		{
			for (unsigned j = 0; j < lenght - 1; j++)
			{
				if (arr[i].getTELE()[k] > arr[j + 1].getTELE()[k])
				{
					NOTE2 temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
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

//NOTE2* Array::getInformation(std::string surname)
//{
//	for (unsigned int i = 0; i < lenght; i++)
//	{
//		std::stringstream streamName(arr[i].getName());
//		std::string _name, _surname;
//		std::getline(streamName, _name, ' ');
//		std::getline(streamName, _surname, ' ');
//		if (surname == _surname) return (arr + i);
//	}
//	return nullptr;
//}

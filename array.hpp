#pragma once
#include "note2.hpp"
#include <sstream>

struct Array
{
private:
	NOTE2* arr;
	size_t lenght;
public:
	Array(size_t lenght);
	~Array() {};
	void setSorted();
	NOTE2* getNOTE2(unsigned int i);
	void setNOTE2(std::string Name, std::string TELE, std::string DATE, unsigned int i);
	size_t getLenght() const;
	int HasInArray(std::string surname) const;
};
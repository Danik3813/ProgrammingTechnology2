#include "note2.hpp"

NOTE2::NOTE2(std::string Name, std::string TELE, std::string DATE)
{
	this->Name = Name;
	this->TELE = TELE;
	this->DATE = DATE;
}

std::string NOTE2::getName()
{
	return Name;
}

std::string NOTE2::getTELE()
{
	return TELE;
}

std::string NOTE2::getDATE()
{
	return DATE;
}

void NOTE2::setName(std::string Name)
{
	this->Name = Name;
}

void NOTE2::setTELE(std::string TELE)
{
	this->TELE = TELE;
}

void NOTE2::setDATE(std::string DATE)
{
	this->DATE = DATE;
}

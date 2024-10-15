#pragma once
#include <string>

struct NOTE2
{
private:
	std::string Name;
	std::string TELE;
	std::string DATE;
public:
	NOTE2() {};
	NOTE2(std::string Name, std::string TELE, std::string DATE);
	std::string getName();
	std::string getTELE();
	std::string getDATE();
	void setName(std::string Name);
	void setTELE(std::string TELE);
	void setDATE(std::string DATE);
};


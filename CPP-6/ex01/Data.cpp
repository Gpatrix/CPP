#include "Data.hpp"

Data::Data(void)
{
	this->Name  = "bob";
	this->Grade = 10;
}

Data::Data(std::string new_name, int new_grade)
{
	this->Name  = new_name;
	this->Grade = new_grade;
}

Data::Data(const Data& copy)
{
	this->operator=(copy);
}

Data&	Data::operator=(const Data& copy)
{
	this->Name  = copy.getName();
	this->Grade = copy.getGrade();
	return (*this);
}

std::string	Data::getName(void) const
{
	return (this->Name);
}

int			Data::getGrade(void) const
{
	return (this->Grade);
}


Data::~Data() {}

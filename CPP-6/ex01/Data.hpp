#pragma once

#include <iostream>
#include <stdint.h>

class Data
{
	private:
		std::string	Name;
		int			Grade;

	public:
		Data(void);
		Data(std::string new_name, int new_grade);
		Data(const Data&);
		
		Data&	operator=(const Data&);
		
		
		std::string	getName(void) const;
		int			getGrade(void) const;

		~Data();
};
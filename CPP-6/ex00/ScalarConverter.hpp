#pragma once

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <ios>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter&);

		ScalarConverter&	operator=(const ScalarConverter&);

		~ScalarConverter(void);

	public:
		static void convert(std::string);
};
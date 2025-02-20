#pragma once

#include <iostream>
#include <sstream>

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
#include "ScalarConverter.hpp"

	ScalarConverter::ScalarConverter(void) {}

	ScalarConverter::ScalarConverter(const ScalarConverter&) {}

	ScalarConverter&	ScalarConverter::operator=(const ScalarConverter&) {return (*this);}



	void ScalarConverter::convert(std::string to_convert)
	{
		double	value;
		char	*end = NULL;
		value = strtod(to_convert.c_str(), &end);
		std::cout << value << "\t" << static_cast<char>(*end) << '\n';

		// char_display(value, to_convert);
	}

	ScalarConverter::~ScalarConverter(void) {}
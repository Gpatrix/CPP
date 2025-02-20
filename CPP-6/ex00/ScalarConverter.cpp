#include "ScalarConverter.hpp"

	ScalarConverter::ScalarConverter(void) {}

	ScalarConverter::ScalarConverter(const ScalarConverter&) {}

	ScalarConverter&	ScalarConverter::operator=(const ScalarConverter&) {return (*this);}



	// static void char_diplay(unsigned char to_display)
	// {
	// 	std::cout << "char: ";

	// 	if (to_display > 177)
	// 		std::cout << "impossible" << '\n';
	// 	else if (to_display >= 32 && to_display <= 126)
	// 		std::cout << '\'' << static_cast<char>(to_display) << "\'\n";
	// 	else
	// 		std::cout << "Non displayable" << '\n';
	// }

	void get_init_value(std::string to_convert)
	{
		std::stringstream ss(to_convert);

		double var;

		ss >> var;

		std::cout << var;
	
		// return (var);
	}

	void ScalarConverter::convert(std::string to_convert)
	{
		get_init_value(to_convert);
		// char_diplay(180);
	}

	ScalarConverter::~ScalarConverter(void) {}
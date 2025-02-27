#include <iostream>
#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "usage: ./RPN [Reverse Polish Notation]\n";
		return (1);
	}
	
	RPN	calculator;

	try
	{
		calculator.calculate(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char**)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file.\n";
		return (1);
	}


	BitcoinExchange	calculator;


	try
	{
		calculator.loadPriceCSV("data.csv");

		// calculator.loadAccountCSV(argv[1]);
		// calculator.printResult();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
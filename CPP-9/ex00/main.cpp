#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file.\n";
		return (1);
	}


	BitcoinExchange	calculator;


	try
	{
		calculator.loadPriceCSV();

		calculator.PrintWalletValue(argv[1]);
		// test les erreur
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
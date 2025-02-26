#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
#include <float.h>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	pricce_map;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange&);

		void	loadPriceCSV(std::string);

		BitcoinExchange&	operator=(const BitcoinExchange&);

		~BitcoinExchange();
};
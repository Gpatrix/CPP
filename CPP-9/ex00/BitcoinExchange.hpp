#pragma once

#include <iostream>
#include <istream>
#include <cmath>
#include <climits>
#include <float.h>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	value;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange&);

		BitcoinExchange&	operator=(const BitcoinExchange&);

		~BitcoinExchange();
};
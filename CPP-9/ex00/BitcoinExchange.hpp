#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cctype>
#include <string>
#include <float.h>
#include <limits.h>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	price_map;

		void	parse_Date(std::string& date);
		void	printValue(std::string&);

		bool	is_good_day(const int&, const int&, const int&);
		double	parse_Value(std::string& value);

		double	calcPrice(std::string&);


	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange&);

		BitcoinExchange&	operator=(const BitcoinExchange&);

		void	loadPriceCSV(void);
		void	PrintWalletValue(char *);

		class BadInputException: public std::exception
		{
			private:
				mutable std::string _message;

			public:
				BadInputException(const std::string message);
				const char* what() const throw();
				~BadInputException(void) throw();
		};

		~BitcoinExchange();
};
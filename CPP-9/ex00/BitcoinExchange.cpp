#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	this->operator=(copy);
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	this->pricce_map = copy.pricce_map;
	return (*this);
}

void	BitcoinExchange::loadPriceCSV(std::string )
{
	std::ifstream	Infile("data.csv");
	if (!Infile.is_open())
	{
		throw std::runtime_error("Error: could not open file data.csv.");
	}

	std::string		buffer;
	std::string		date;
	double			price;

	std::getline(Infile, buffer);

	while (!Infile.eof())
	{
		std::getline(Infile, buffer, ',');
		if (buffer.empty())
			break;
		date = buffer;

		std::getline(Infile, buffer);
		price = strtod(buffer.c_str(), NULL);

		this->pricce_map.insert(std::pair<std::string, double>(date, price));
	}
}


BitcoinExchange::~BitcoinExchange() {}
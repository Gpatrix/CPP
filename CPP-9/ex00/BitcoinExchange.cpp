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

void	BitcoinExchange::loadPriceCSV(void)
{
	std::ifstream	Infile("data.csv");
	if (!Infile.is_open())
		throw std::runtime_error("Error: could not open file data.csv.");

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

void	BitcoinExchange::parse_Date(std::string& date)
{
	if (date.size() != 11)
		throw BadInputException(date);
	if (!(std::isdigit(date[0]) && std::isdigit(date[1])
		&& std::isdigit(date[2]) && std::isdigit(date[3])
		&& date[4] == '-'
		&& std::isdigit(date[5]) && std::isdigit(date[6]) && strtol(date.substr(5,6).c_str(), NULL, 10) <= 12
		&& date[7] == '-'
		&& std::isdigit(date[8]) && std::isdigit(date[9]) && strtol(date.substr(8,9).c_str(), NULL, 10) <= 31
		&& date[10] == ' '
		))
	{
		std::cout << "bad\n";
	}
	else
	{
		std::cout << "good\n";
	}
	
}


void	BitcoinExchange::printValue(std::string& buffer)
{
	std::string	date;
	std::string	value;

	std::stringstream stream(buffer);

	std::getline(stream, date, '|');
	if (stream.eof())
		throw BadInputException(date);
	parse_Date(date);
	// std::getline(stream, date);
	// parse_value(value);
	//print result
}

void	BitcoinExchange::PrintWalletValue(char * file)
{
	std::ifstream	Infile(file);
	if (!Infile.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string		buffer;
	std::getline(Infile, buffer);

	while (!Infile.eof())
	{
		std::getline(Infile, buffer);
		if (buffer.empty())
			break;
		try
		{
			printValue(buffer);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

BitcoinExchange::BadInputException::BadInputException(const std::string message): _message(message) {}

const char* BitcoinExchange::BadInputException::what() const throw()
{
	this->_message = "Error: bad input => " + this->_message;
	return (this->_message.c_str());
}

BitcoinExchange::BadInputException::~BadInputException(void) throw() {}

BitcoinExchange::~BitcoinExchange() {}
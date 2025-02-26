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

bool	BitcoinExchange::is_good_day
(
	const int& year_nb,
	const int& month_nb,
	const int& day_nb
)
{
	int	max_day = 0;

	if (month_nb == 2)
	{
		if (year_nb % 4 == 0 && (year_nb % 100 != 0 || year_nb % 400 == 0)) // is_bissextile
			max_day = 29;
		else
			max_day = 28;
	}
	else if (month_nb % 2 != 0)
		max_day = 31;
	else
		max_day = 30;
	
	return (day_nb <= max_day && day_nb != 0);
}

void	BitcoinExchange::parse_Date(std::string& date)
{
	if (date.size() != 11)
		throw BadInputException(date);
	if (!(std::isdigit(date[0]) && std::isdigit(date[1])
		&& std::isdigit(date[2]) && std::isdigit(date[3])
		&& date[4] == '-'
		&& std::isdigit(date[5]) && std::isdigit(date[6])
		&& date[7] == '-'
		&& std::isdigit(date[8]) && std::isdigit(date[9])
		&& date[10] == ' '
		))
	{
		throw	BadInputException(date);
	}

	int	year_nb  = strtol(date.substr(0,3).c_str(), NULL, 10);
	int	month_nb = strtol(date.substr(5,6).c_str(), NULL, 10);
	int	day_nb   = strtol(date.substr(8,9).c_str(), NULL, 10);

	if (month_nb == 0 || month_nb > 12 || !is_good_day(year_nb, month_nb, day_nb))
		throw	BadInputException(date);
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
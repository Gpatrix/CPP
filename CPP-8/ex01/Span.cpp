#include "Span.hpp"

Span::Span(void): storage(0), _max_value_nb(0) {}

Span::Span(unsigned int N): storage(0), _max_value_nb(N) {}

Span::Span(const Span& copy): storage(copy.storage) {}

Span&	Span::operator=(const Span& copy)
{
	this->storage = copy.storage;
	return (*this);
}

void Span::addNumber(int new_nb)
{
	if (this->storage.size() >= this->_max_value_nb)
		throw MaxValueNbexeption();
	
	this->storage.push_back(new_nb);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (end - begin + this->storage.size() > this->_max_value_nb)
		throw MaxValueNbexeption();

	this->storage.insert(this->storage.begin(), begin, end);
}

unsigned int	Span::shortestSpan(void)
{
	if (this->storage.size() <= 1)
		throw NoSpanFoudexeption();
	
	unsigned int	min = UINT_MAX;
	unsigned int	tmp = UINT_MAX;

	std::sort(this->storage.begin(), this->storage.end());
	for (std::vector<int>::iterator it = this->storage.begin(); it < this->storage.end(); it++)
	{
		tmp = *(it + 1) - *it;
		if (tmp < min)
			min = tmp;
	}

	return (min);
}

unsigned int	Span::longestSpan(void)
{
	if (this->storage.size() <= 1)
		throw NoSpanFoudexeption();
	
	int max = *std::max_element(this->storage.begin(), this->storage.end());
	int min = *std::min_element(this->storage.begin(), this->storage.end());
	return (max - min);
}

const char* Span::NoSpanFoudexeption::what() const throw()
{
	return ("the could not be found");
}

const char* Span::MaxValueNbexeption::what() const throw()
{
	return ("Max nb of value reach");
}

Span::~Span() {}
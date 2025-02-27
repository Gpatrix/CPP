#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}
PmergeMe::PmergeMe(const PmergeMe& copy)
{
	this->operator=(copy);
}
PmergeMe&	PmergeMe::operator=(const PmergeMe& copy)
{
	this->top_list = copy.top_list;
	this->bottom_list = copy.bottom_list;
	return (*this);
}


void	PmergeMe::init_bottom(int& argc, char** &argv)
{
	double	nb;
	char*	end;
	for (int index = 1; index < argc; index++)
	{
		nb = strtol(argv[index], &end, 10);
		if (nb < 0 || *end != '\0')
			throw std::runtime_error("Bad args");
		
		this->bottom_list.push_back(static_cast<int>(nb));
	}
}


PmergeMe::~PmergeMe(void) {}
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
	long	nb;
	char*	end;
	for (int index = 1; index < argc; index++)
	{
		nb = strtol(argv[index], &end, 10);
		if (nb < 0 || *end != '\0' || !std::isdigit(argv[index][0]))
			throw std::runtime_error("Bad args");
		
		this->bottom_list.push_back(static_cast<int>(nb));
	}
}

void	PmergeMe::show(std::list<int>& list)
{
	for (std::list<int>::iterator it = list.begin()
	; it != list.end(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << '\n';
}

void	PmergeMe::sort(void)
{
	std::cout << "Before:  ";
	this->show(this->bottom_list);
	
}

PmergeMe::~PmergeMe(void) {}
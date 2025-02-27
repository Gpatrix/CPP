#include "PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe(void) {}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& copy)
{
	this->operator=(copy);
}

template <typename T>
PmergeMe<T>&	PmergeMe<T>::operator=(const PmergeMe<T>& copy)
{
	this->_top = copy._top;
	this->_bottom = copy._bottom;
	return (*this);
}

template <typename T>
void PmergeMe<T>::print_before(void)
{
	for (typename T::iterator it = this->_bottom.begin()
	; it != this->_bottom.end(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << '\n';
}

template <typename T>
void PmergeMe<T>::print_after(void)
{
	for (typename T::iterator it = this->_top.begin()
	; it != this->_top.end(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << '\n';
}

#include <unistd.h>
template <typename T>
void	PmergeMe<T>::print_time(void)
{
	std::cout << std::fixed << this->_time << " seconds\n";
}


template <typename T>
void	PmergeMe<T>::init_bottom(int& argc, char** &argv)
{
	long	nb;
	char*	end;
	clock_t	_start_time = clock();

	for (int index = 1; index < argc; index++)
	{
		nb = strtol(argv[index], &end, 10);
		if (nb < 0 || *end != '\0' || !std::isdigit(argv[index][0]))
			throw std::runtime_error("Error");
		
		this->_bottom.push_back(static_cast<int>(nb));
	}
	this->_time = static_cast<double>(clock() - _start_time) / CLOCKS_PER_SEC;
}

template <typename T>
void	PmergeMe<T>::split_list(void)
{
	typename T::iterator it = this->_bottom.begin();
	int nb_pair = this->_bottom.size() / 2;
	for (int paire = 0; paire < nb_pair; paire++)
	{
		if (*it > *(it + 1))
		{
			this->_top.push_back(*it);
			this->_bottom.erase(it);
		}
		else
		{
			this->_top.push_back(*(it + 1));
			this->_bottom.erase(it + 1);
		}
		it++;
	}
}


template <typename T>
void	PmergeMe<T>::sort(void)
{
	// std::cout << "Before:  ";
	// this->show(this->_bottom);
	clock_t	_start_time = clock();
	// TODO start time
	if (this->_bottom.size() != 1)
	{
		this->split_list();
		// bla bla bla
	}
	else
	{
		this->_top.push_back(this->_bottom[0]);
	}
	
	// TODO end time
	this->_time += static_cast<double>(clock() - _start_time) / CLOCKS_PER_SEC;

	// std::cout << "after:   ";
	// this->show(this->_top);
}

template <typename T>
PmergeMe<T>::~PmergeMe(void) {}
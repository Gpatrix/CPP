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


template <typename T>
void	PmergeMe<T>::init_bottom(int& argc, char** &argv)
{
	long	nb;
	char*	end;
	for (int index = 1; index < argc; index++)
	{
		nb = strtol(argv[index], &end, 10);
		if (nb < 0 || *end != '\0' || !std::isdigit(argv[index][0]))
			throw std::runtime_error("Error");
		
		this->_bottom.push_back(static_cast<int>(nb));
	}
}

// void	PmergeMe::split_list(void)
// {
// 	// if ()
// 	// {
// 	// 	/* code */
// 	// }
// }


template <typename T>
void	PmergeMe<T>::sort(void)
{
	// std::cout << "Before:  ";
	// this->show(this->_bottom);
	// TODO start time
	if (this->_bottom.size() != 1)
	{
		this->split_list();
		//bla bla bla
	}
	// TODO end time

	// std::cout << "after:   ";
	// this->show(this->_top);
}

template <typename T>
PmergeMe<T>::~PmergeMe(void) {}
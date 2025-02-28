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
void PmergeMe<T>::show(void)
{
	for (typename T::iterator it = this->_main_list.begin()
	; it != this->_main_list.end(); it++)
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
void	PmergeMe<T>::init_list(int& argc, char** &argv)
{
	double	nb;
	char*	end;
	clock_t	_start_time = clock();

	for (int index = 1; index < argc; index++)
	{
		nb = std::strtod(argv[index], &end);
		if (nb < 0 || nb > __INT_MAX__|| *end != '\0' || !std::isdigit(argv[index][0]))
			throw std::runtime_error("Error");
		
		this->_main_list.push_back(static_cast<int>(nb));
	}
	this->_time = static_cast<double>(clock() - _start_time) / CLOCKS_PER_SEC;
}

template <typename T>
void	PmergeMe<T>::split_list(T& list, T& larger, T& smaller, int& size)
{
	for (int i = 0; i < size; i++)
	{
		if (list[2 * i] > list[2 * i + 1])
		{
			larger.push_back(list[2 * i]);
			smaller.push_back(list[2 * i + 1]);
		}
		else
		{
			larger.push_back(list[2 * i + 1]);
			smaller.push_back(list[2 * i]);
		}
	}
}

template <typename T>
void	PmergeMe<T>::sort(void)
{
	clock_t	_start_time = clock();

	mergeInsertionSort(this->_main_list, this->_main_list.size());

	this->_time += static_cast<double>(clock() - _start_time) / CLOCKS_PER_SEC;

}

template <typename T>
int	PmergeMe<T>::binarySearch(T& list, int left, int right, int& key)
{
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (list[mid] < key)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

template <typename T>
void	PmergeMe<T>::insertElement(T& list, int& size, int& element)
{
	int pos = binarySearch(list, 0, size, element);

	list.insert(list.begin() + pos, element);

	size++;
}

template <typename T>
void PmergeMe<T>::mergeInsertionSort(T& list, int n)
{
	if (n <= 1)
		return;

	int pairedSize = n / 2;
	T larger;
	T smaller;
	int sortedSize = 0;

	this->split_list(list, larger, smaller, pairedSize);

	int unpaired = (n % 2 == 1) ? list[n - 1] : -1;

	mergeInsertionSort(larger, pairedSize);

	sortedSize = pairedSize;
	
	insertElement(larger, sortedSize, smaller[0]);

	T	insertionOrder;
	int	orderIndex = 0;

	for (int i = 1; i < pairedSize; i++)
	{
		insertionOrder.push_back(smaller[i]);
		orderIndex++;
	}
	if (n % 2 == 1)
	{
		insertionOrder.push_back(unpaired);
		orderIndex++;
	}

	for (int i = 0; i < orderIndex; i++)
		insertElement(larger, sortedSize, insertionOrder[i]);

	for (int i = 0; i < sortedSize; i++)
		list[i] = larger[i];
}

template <typename T>
PmergeMe<T>::~PmergeMe(void) {}
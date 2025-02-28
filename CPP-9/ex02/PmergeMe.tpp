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
		
		this->_main_list.push_back(static_cast<int>(nb));
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
	clock_t	_start_time = clock();

	mergeInsertionSort(this->_main_list, this->_main_list.size());

	this->_time += static_cast<double>(clock() - _start_time) / CLOCKS_PER_SEC;

}

// Function to perform binary search for insertion
template <typename T>
int	PmergeMe<T>::binarySearch(T& arr, int left, int right, int& key)
{
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] < key)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

// Function to insert an element at the correct position
template <typename T>
void	PmergeMe<T>::insertElement(T arr, int& size, int& element)
{
	int pos = binarySearch(arr, 0, size, element);
	for (int i = size; i > pos; i--)
		arr[i] = arr[i - 1];
	arr[pos] = element;
	size++;
}

// Merge-Insertion Sort function
template <typename T>
void PmergeMe<T>::mergeInsertionSort(T& arr, int n)
{
	if (n <= 1)
		return;

	int pairedSize = n / 2;
	T larger;
	T smaller;
	int sortedSize = 0;

	// Step 1: Pair elements and find larger/smaller
	for (int i = 0; i < pairedSize; i++)
	{
		if (arr[2 * i] > arr[2 * i + 1])
		{
			larger.push_back(arr[2 * i]);
			smaller.push_back(arr[2 * i + 1]);
		}
		else
		{
			larger.push_back(arr[2 * i + 1]);
			smaller.push_back(arr[2 * i]);
		}
	}

	// If n is odd, handle the last element
	int unpaired = (n % 2 == 1) ? arr[n - 1] : -1;

	// Step 2: Recursively sort the larger elements
	mergeInsertionSort(larger, pairedSize);

	// Step 3: Insert the first smaller element into sorted sequence
	sortedSize = pairedSize;
	T sorted;
	for (int i = 0; i < pairedSize; i++)
		sorted.push_back(larger[i]);
	insertElement(sorted, sortedSize, smaller[0]);

	// // Step 4: Insert remaining elements in specific order
	T	insertionOrder;
	int	orderIndex = 0;

	// // Generate insertion order as per the algorithm
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

	// Perform binary insertion
	for (int i = 0; i < orderIndex; i++)
		insertElement(sorted, sortedSize, insertionOrder[i]);

	std::cout << '\n';
	for (typename T::iterator it = sorted.begin()
	; it != sorted.end(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << '\n';
	

	// Copy sorted elements back to original array
	for (int i = 0; i < sortedSize; i++)
		this->_main_list[i] = sorted[i];
}

template <typename T>
PmergeMe<T>::~PmergeMe(void) {}
#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <time.h>

template <typename T>
class PmergeMe
{
	private:
		T		_main_list;
		double	_time;

		void	split_list(T& list, T& larger, T& smaller, int& size);
		void	mergeInsertionSort(T& arr, int n);
		void	insertElement(T& arr, int& size, int& element);
		int		binarySearch(T& arr, int left, int right, int& key);

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe&);
		PmergeMe&	operator=(const PmergeMe&);

		void	init_list(int&, char** &);
		void	sort(void);

		void	show(void);
		void	print_time(void);


		~PmergeMe(void);
};


#include "PmergeMe.tpp"
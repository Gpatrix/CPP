#pragma once

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
#include <cmath>
#include <time.h>

template <typename T>
class PmergeMe
{
	private:
		T		_main_list;
		double	_time;

		void	split_list(void);
		void mergeInsertionSort(T& arr, int& n);

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe&);
		PmergeMe&	operator=(const PmergeMe&);

		void	init_bottom(int&, char** &);
		void	sort(void);

		void	show(void);
		void	print_time(void);


		~PmergeMe(void);
};


#include "PmergeMe.tpp"
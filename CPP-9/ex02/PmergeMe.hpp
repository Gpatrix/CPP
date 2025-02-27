#pragma once

#include <iostream>
#include <list>
#include <stdlib.h>
#include <cstring>
#include <cmath>

template <typename T>
class PmergeMe
{
	private:
		T		_top;
		T		_bottom;
		clock_t	time;

		void	split_list(void);

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe&);
		PmergeMe&	operator=(const PmergeMe&);

		void	init_bottom(int&, char** &);
		void	sort(void);

		void	print_before(void);
		void	print_after(void);
		void	print_time(void);


		~PmergeMe(void);
};


#include "PmergeMe.tpp"
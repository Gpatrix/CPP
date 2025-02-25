#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <limits.h>

class Span
{
	private:
		std::vector<int>	storage;
		unsigned int		_max_value_nb;

	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span&);
		Span&	operator=(const Span&);

		void addNumber(int new_nb);

		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

		class NoSpanFoudexeption: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class MaxValueNbexeption: public std::exception
		{
			public:
				const char* what() const throw();
		};

		~Span();
};

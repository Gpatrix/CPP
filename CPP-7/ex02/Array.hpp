#pragma once

#include <iostream>
#include <stdint.h>
#include <exception>
#include  <cstring>

template <typename T>
class Array
{
	private:
		T*				_Array;
		unsigned int	_size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array&);
		~Array(void);

		Array&	operator=(const Array&);

		T	operator[](unsigned int idx);
		T&	operator[](unsigned int idx) const;

		class OutOfBoundsexeption: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#include "Array.cpp"
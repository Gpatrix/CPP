#pragma once

#include <iostream>
#include <stdint.h>
#include <exception>


template <typename T>
class Array
{
	private:
		T*	_Array;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array&);
		~Array(void);

		Array&	operator=(const Array&);

		T	operator[](unsigned int idx);
		T&	operator[](unsigned int idx) const;

		unsigned int	size(void) const;

		class OutOfBoundsexeption: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

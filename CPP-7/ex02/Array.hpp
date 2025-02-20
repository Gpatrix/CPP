#pragma once

#include <iostream>
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

		Array&	operator=(const Array&);

		class OutOfBoundsexeption: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

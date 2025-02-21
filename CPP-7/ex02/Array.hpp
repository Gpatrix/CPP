#pragma once

#include <iostream>
#include <cstdint>
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

		T&	operator[](int idx) const;
		T	operator[](int idx) const;

		class OutOfBoundsexeption: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

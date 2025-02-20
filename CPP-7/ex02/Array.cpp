#include "Array.hpp"

template <typename T>
Array<T>::Array(void): Array(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n)
{
	if (n > 0)
		Array = new T[n];
	else
		Array = NULL;
}
// Array::Array(const Array&);

// Array&	Array::operator=(const Array&);

// const char* Array::OutOfBoundsexeption::what() const throw()
// {
	
// }
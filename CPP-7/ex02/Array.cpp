#include "Array.hpp"

template <typename T>
Array<T>::Array(void): Array(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n)
{
	if (n > 0)
		this->_Array = new T[n];
	else
		this->_Array = NULL;
}
template <typename T>
Array<T>::Array(const Array<T>& copy)
{
	this->operator=(copy);
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& copy)
{
	if (*this == copy)
		return (*this);
	
	if (!copy._Array)
	{
		this->_Array = NULL;
		return (*this);
	}

	size_t	size = sizeof(copy._Array)/sizeof(copy._Array[0]);

	for (size_t i = 0; i < size; i++)
	{
		this->_Array[i] = copy._Array[i];
	}
	return (*this);
}



// const char* Array::OutOfBoundsexeption::what() const throw()
// {
	
// }
#include "Array.hpp"



template <typename T>
size_t	Array<T>::size(void) const
{
	if (!this->_Array)
		return (0);
	else
		return (sizeof(this->_Array)/sizeof(this->_Array[0]));
}

template <typename T>
Array<T>::Array(void): _Array(NULL) {}

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

	size_t	size = copy.size();

	for (size_t i = 0; i < size; i++)
	{
		this->_Array[i] = copy._Array[i];
	}
	return (*this);
}


template <typename T>
T&	Array<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= this->size())
		throw this->OutOfBoundsexeption();
	return (this->_Array[idx]);
}

template <typename T>
const char* Array<T>::OutOfBoundsexeption::what() const throw()
{
	return ("Out of bound");
}
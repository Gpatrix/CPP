#include "Array.hpp"

template <typename T>
Array<T>::Array(void): _Array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n)
{
	if (n > 0)
	{
		this->_Array = new T[n];
		this->_size  = n;
		memset(this->_Array, 0, n * sizeof(T));
	}
	else
	{
		this->_Array = NULL;
		this->_size  = 0;
	}
}
template <typename T>
Array<T>::Array(const Array<T>& copy): _Array(NULL)
{
	this->operator=(copy);
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& copy)
{
	if (this == &copy)
		return (*this);

	if (!copy._Array)
	{
		this->_Array = NULL;
		this->_size  = 0;
		return (*this);
	}

	if (this->_Array)
		delete this->_Array;

	this->_Array = new T[copy._size];
	this->_size  = copy._size;
	for (unsigned int	i = 0; i < copy._size; i++)
	{
		this->_Array[i] = copy._Array[i];
	}

	return (*this);
}

template <typename T>
T	Array<T>::operator[](unsigned int idx) const
{
	if (idx >= this->_size)
		throw OutOfBoundsexeption();
	return (this->_Array[idx]);
}

template <typename T>
T&	Array<T>::operator[](unsigned int idx)
{
	if (idx >= this->_size)
		throw OutOfBoundsexeption();
	return (this->_Array[idx]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
const char* Array<T>::OutOfBoundsexeption::what() const throw()
{
	return ("Out of bound");
}

template <typename T>
Array<T>::~Array(void)
{
	if (this->_Array)
		delete[] this->_Array;
}

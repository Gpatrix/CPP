#include "MutantStack.hpp"


template <typename T>
MutantStack<T>::MutantStack(void)
{

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& copy)
{
	this->operator=(copy);
}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T>& copy)
{
	MutantStack<int>::iterator it = copy.begin();

	for (; it < copy.end(); it++)
	{
		this->push(*it);
	}
}

template <typename T>
MutantStack<T>::~MutantStack() {}
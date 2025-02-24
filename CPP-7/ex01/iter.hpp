#pragma once
#include <iostream>

template <typename T> 
void iter(const T* array, int len, void (*fonct)(const T&))
{
	int	index = 0;

	while (index < len)
	{
		fonct(array[index]);
		index++;
	}
}

template <typename T> 
void iter(T* array, int len, void (*fonct)( T&))
{
	int	index = 0;

	while (index < len)
	{
		fonct(array[index]);
		index++;
	}
}

template <typename T> 
void display_iter(const T& to_increment)
{
	std::cout << to_increment << '\n';
}
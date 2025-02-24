#pragma once
#include <iostream>
#include <algorithm>

// metre evaleur de routoure
template <typename T>
typename T::iterator easyfind(T container, int nb)
{
	typename T::iterator it = std::find(container.begin(), container.end(), nb);

	if (it == container.end())
	{
		throw std::runtime_error("exexption: Value not foud");
	}
	return (it);
}
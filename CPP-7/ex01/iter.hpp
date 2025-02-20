#pragma once

template <typename T> void iter(T* array, int len, void(*fonct)(T&))
{
	int	index = 0;

	while (index < len)
	{
		fonct(array[index]);
		index++;
	}
}

template <typename T> void increment_iter(T& to_increment)
{
	to_increment++;
}
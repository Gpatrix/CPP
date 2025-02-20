#include <iostream>
#include "iter.hpp"

#define array_len 10

int main(void)
{

	{
		int test[array_len] = {};

		std::cout << "befor:\n";
		for (size_t i = 0; i < array_len; i++)
		{
			std::cout << test[i] << ",";
		}
		std::cout << '\n';

		::iter(test, array_len, &increment_iter);

		std::cout << "after:\n";
		for (size_t i = 0; i < array_len; i++)
		{
			std::cout << test[i] << ",";
		}
	}


		std::cout << "\n\n";
	
	
	{
		char test[array_len] = {};
		for (size_t i = 0; i < array_len; i++)
			test[i] = 'a';

		std::cout << "befor:\n";
		for (size_t i = 0; i < array_len; i++)
		{
			std::cout << test[i] << ",";
		}
		std::cout << '\n';

		::iter(test, array_len, &increment_iter);

		std::cout << "after:\n";
		for (size_t i = 0; i < array_len; i++)
		{
			std::cout << test[i] << ",";
		}
	}

	return (0);
}
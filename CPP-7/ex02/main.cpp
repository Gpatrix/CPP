#include <iostream>
#include <vector>
#include "Array.hpp"

int main(void)
{
	try
	{
		Array<int> new_array(5);
		new_array[0] = 5;
		Array<int> cpy_array(new_array);
		std::cout << cpy_array[0] << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		const Array<int> new_array(5);
		// new_array[0] = 5;
		std::cout << new_array[0] << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Array<int> new_array(5);
		new_array[50] = 5;
		std::cout << new_array[0] << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return (0);

}

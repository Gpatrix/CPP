#include <iostream>
#include <vector>
#include <queue>
#include "easyfind.hpp"


int main(void)
{
	try
	{
		std::vector<int> vectar(2);
		vectar[0] = 2;
		vectar[1] = 5;

		easyfind<std::vector<int> >(vectar, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::vector<int> vector(50);

		easyfind<std::vector<int> >(vector, 54);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

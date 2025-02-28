#include <iostream>
#include <vector>
#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	PmergeMe<std::vector<int> > algo;

	if (argc == 1)
	{
		std::cerr << "usage: ./PmergeMe [...]\n";
		return (1);
	}

	try
	{
		algo.init_bottom(argc, argv);

		std::cout << "Before:  ";
		algo.show();

		algo.sort();

		std::cout << "after:   ";
		algo.show();

		algo.print_time();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
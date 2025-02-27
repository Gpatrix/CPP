#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	PmergeMe algo;

	if (argc == 1)
	{
		std::cerr << "usage: ./PmergeMe [...]\n";
		return (1);
	}
	
	try
	{
		algo.init_bottom(argc, argv);

		algo.sort();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}
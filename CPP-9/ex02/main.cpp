#include <iostream>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	PmergeMe<std::vector<int> > algo_vector;
	PmergeMe<std::deque<int> > algo_deque;

	if (argc == 1)
	{
		std::cerr << "usage: ./PmergeMe [...]\n";
		return (1);
	}

	try
	{
		algo_vector.init_bottom(argc, argv);

		std::cout << "Before:  ";
		algo_vector.show();

		algo_vector.sort();

		std::cout << "after:   ";
		algo_vector.show();

		algo_vector.print_time();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
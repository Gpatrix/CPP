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
		algo_deque.init_bottom(argc, argv);

		std::cout << "Before:  ";
		algo_vector.show();

		algo_vector.sort();
		algo_deque.sort();

		std::cout << "after:   ";
		algo_vector.show();

		std::cout << "Time to process a range of 5 elements with std::vector :   ";
		algo_vector.print_time();

		std::cout << "Time to process a range of 5 elements with std::deque  :   ";
		algo_deque.print_time();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
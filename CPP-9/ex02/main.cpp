#include <iostream>
#include <vector>
#include "PmergeMe.hpp"


// https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort
// https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort
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
		algo.print_before();
		algo.sort();
		std::cout << "after:   ";
		algo.print_after();
		algo.print_time();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}
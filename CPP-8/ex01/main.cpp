#include <iostream>
#include <ctime>
#include "Span.hpp"

int main()
{

	try
	{
		Span sp = Span(5);

		std::vector<int> other;
		for (size_t i = 0; i < 5; i++)
		{
			other.push_back(i);
		}
		
		sp.addNumber(other.begin(), other.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
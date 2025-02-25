#include <iostream>
#include <ctime>
#include "Span.hpp"

int main()
{
	Span sp = Span(1000);

	std::srand(std::time(NULL));

	try
	{
		for (size_t i = 0; i < 1000; i++)
		{
			sp.addNumber(std::rand() % __INT16_MAX__);
		}
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
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
	return 0;
}
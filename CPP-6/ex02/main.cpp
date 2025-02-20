#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	std::srand(std::time(NULL));
	switch (std::rand() % 3)
	{
	case 0:
		std::cout << "created A\n";
		return (new A);
		break;

	case 1:
		std::cout << "created B\n";
		return (new B);
		break;
	
	case 2:
		std::cout << "created C\n";
		return (new C);
		break;
	}
	return (NULL);
}

void identify(Base* p)
{
	A* new_A = dynamic_cast<A*>(p);
	if (new_A != NULL)
	{
		std::cout << "pointer is of type A" << '\n';
		return;
	}
	B* new_B = dynamic_cast<B*>(p);
	if (new_B != NULL)
	{
		std::cout << "pointer is of type B" << '\n';
		return;
	}
	C* new_C = dynamic_cast<C*>(p);
	if (new_C != NULL)
	{
		std::cout << "pointer is of type C" << '\n';
		return;
	}
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "pointer is of type A" << '\n';
		return;
	}
	catch (std::exception& e) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "pointer is of type B" << '\n';
		return;
	}
	catch (std::exception& e) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "pointer is of type C" << '\n';
		return;
	}
	catch (std::exception& e) {}
}

int main(void)
{
	Base*	pop;
	pop = generate();

	identify(pop);
	identify(*pop);
	delete pop;
	return (0);
}

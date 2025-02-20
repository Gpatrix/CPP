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

void identify(Base* p);

int main(void)
{
	Base*	pop;
	pop = generate();
	delete pop;
	return (0);
}

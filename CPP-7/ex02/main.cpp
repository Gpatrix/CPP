#include <iostream>

int main(void)
{
	int test[4];

	std::cout << sizeof(test)/sizeof(test[0]);
	return (0);
}

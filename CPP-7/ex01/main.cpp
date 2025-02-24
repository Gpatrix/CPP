#include <iostream>
#include "iter.hpp"


int main(void)
{
	int test[5] = {1, 2, 3, 4, 5};

	::iter(test, 5, &display_iter);
	return (0);
}
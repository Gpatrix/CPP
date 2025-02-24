
#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"
#include <stdint.h>

int main(void)
{
	Data		data("louis", 1);
	uintptr_t	ptr;
	Data		*same_data;

	ptr = Serializer::serialize(&data);

	same_data = Serializer::deserialize(ptr);

	std::cout << &same_data << " " << same_data->getName() << " " << same_data->getGrade() << '\n'
			<< &data << " " << data.getName() << " " << data.getGrade() << '\n';
	return (0);
}

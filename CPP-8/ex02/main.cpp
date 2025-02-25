#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top: " << mstack.top() 
	<< " | size: " << mstack.size() << '\n';

	mstack.pop();

	std::cout << "new top: " << mstack.top()
	<< " | new size: " << mstack.size() << '\n';

	mstack.push(3);
	mstack.push(5);
	mstack.push(80);
	mstack.push(1);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	++it;
	--it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	return (0);
}

// int main(void)
// {
// 	std::list<int> mylist;

// 	mylist.push_back(5);
// 	mylist.push_back(17);

// 	std::cout << "top: " << *mylist.begin()
// 	<< " | size: " << mylist.size() << '\n';

// 	mylist.pop_front();

// 	std::cout << "new top: " << *mylist.begin()
// 	<< " | new size: " << mylist.size() << '\n';

// 	mylist.push_back(3);
// 	mylist.push_back(5);
// 	mylist.push_back(80);
// 	mylist.push_back(1);

// 	std::list<int>::iterator it = mylist.begin();
// 	std::list<int>::iterator ite = mylist.end();

// 	++it;
// 	++it;
// 	--it;
// 	--it;

// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}

// 	std::list<int> s(mylist);
// 	return (0);
// }
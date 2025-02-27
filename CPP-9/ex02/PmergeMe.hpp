#include <iostream>
#include <list>
#include <stdlib.h>
#include <cstring>
#include <cmath>

class PmergeMe
{
	private:
		std::list<int> top_list;
		std::list<int> bottom_list;
		void	show(std::list<int>&);

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe&);
		PmergeMe&	operator=(const PmergeMe&);

		void	init_bottom(int&, char** &);
		void	sort(void);

		~PmergeMe(void);
};
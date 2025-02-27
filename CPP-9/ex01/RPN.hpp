#include <iostream>
#include <stack>
#include <cctype>

class RPN
{
	private:
		std::stack<int> my_stack;
		void	check_arg(const char&) const;
		void	do_arg(const char&);
		void	do_cal(const char&);

	public:
		RPN(void);
		RPN(const RPN&);
		RPN&	operator=(const RPN&);


		void	calculate(char* &);

		~RPN(void);
};
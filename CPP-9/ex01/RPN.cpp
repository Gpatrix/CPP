#include "RPN.hpp"

RPN::RPN(void) {}
RPN::RPN(const RPN& copy)
{
	this->operator=(copy);
}
RPN&	RPN::operator=(const RPN& copy)
{
	if (this != &copy)
		this->my_stack = copy.my_stack;
	return (*this);
}

void	RPN::check_arg(const char& input) const
{
	if (!(std::isdigit(input) || input == '+' || input == '-' || input == '/' || input == '*'))
	{
		throw std::runtime_error("Error");
	}
}

void	RPN::do_cal(const char& input)
{
	int	result;
	
	int	right  = this->my_stack.top();

	this->my_stack.pop();

	int	left = this->my_stack.top();

	this->my_stack.pop();

	switch (input)
	{
		case '+':
			result = left + right;
			break;

		case '-':
			result = left - right;
			break;

		case '*':
			result = left * right;
			break;
		
		case '/':
			if (right == 0)
				throw std::runtime_error("Error");

			result = left / right;
			break;
	}

	this->my_stack.push(result);
}

void	RPN::do_arg(const char& input)
{
	if (std::isdigit(input))
	{
		this->my_stack.push(input - '0');
	}
	else
	{
		if (this->my_stack.size() < 2)
			throw std::runtime_error("Error");

		do_cal(input);
	}
}

void	RPN::calculate(char* &info)
{
	bool	is_space = false;
	while (*info)
	{
		if (is_space)
		{
			if (*info != ' ')
				throw std::runtime_error("Error");
			else
			{
				is_space = false;
				info++;
				continue;
			}
		}
		
		check_arg(*info);

		do_arg(*info);

		is_space = !is_space;
		info++;
	}
	
	if (this->my_stack.size() != 1)
		throw std::runtime_error("Error");

	std::cout << this->my_stack.top() << '\n';
}


RPN::~RPN(void) {}
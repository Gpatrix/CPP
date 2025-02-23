/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:51:56 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/23 15:58:53 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter::~ScalarConverter(void) {}

static void	char_display(long& nb, char* end, std::string& str)
{
	std::cout << "char: ";
	if (end == str.c_str() || nb < CHAR_MIN || CHAR_MAX < nb)
		std::cout << IMPOSSIBLE;
	else if (nb < 32 || nb > 126)
		std::cout << NON_DISPLAYABLE;
	else
		std::cout << '\'' << static_cast<char>(nb) << '\'';

	std::cout << '\n';
}

static void	int_display(long& nb, char* end, std::string& str)
{
	std::cout << "int: ";
	if (end == str.c_str() || nb < INT_MIN || INT_MAX < nb)
		std::cout << IMPOSSIBLE;
	else
		std::cout << static_cast<int>(nb);
	std::cout << '\n';
}

static void	float_display(double& nb, char* end, std::string& str)
{
	std::cout << "float: ";
	if (end == str.c_str() || ((nb < FLT_MIN || FLT_MAX < nb) && !std::isinf(nb)))
		std::cout << IMPOSSIBLE;
	else if (static_cast<float>(nb) == ceilf(static_cast<float>(nb)) && !std::isinf(nb))
		std::cout << std::fixed << std::setprecision(0) << static_cast<float>(nb) << ".0f";
	else
		std::cout << static_cast<float>(nb) << "f";
	std::cout << '\n';
}

static void	double_display(double& nb, char* end, std::string& str)
{
	std::cout << "double: ";
	if (end == str.c_str() && !std::isinf(nb))
		std::cout << IMPOSSIBLE;
	else if (nb == ceil(nb)  && !std::isinf(nb))
		std::cout << std::fixed << std::setprecision(0) << nb << ".0";
	else
		std::cout << nb;
	std::cout << '\n';
}

void	ScalarConverter::convert(std::string str)
{
	char				*end;
	double				d;
	long				l;

	d = strtod(str.c_str(), &end);
	l = static_cast<long>(d);

	char_display(l, end, str);

	int_display(l, end, str);

	float_display(d, end, str);

	double_display(d, end, str);
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &other __attribute__((unused)))
{
	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:16:49 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/13 12:14:42 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	std::string	name("bob");
	int			grade = 150;

	try
	{
		Bureaucrat bob(name, grade);
		std::cout << bob;
		bob.incrementGrade();
		std::cout << bob;
		bob.decrementGrade();
		bob.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << '\n';
	}

	grade = 0;
	try
	{
		Bureaucrat bob(name, grade);
		std::cout << bob;
		bob.incrementGrade();
		std::cout << bob;
		bob.decrementGrade();
		bob.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << '\n';
	}



	return 0;
}

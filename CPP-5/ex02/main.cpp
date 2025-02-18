/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:16:49 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/18 09:27:51 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	std::string	bureaucrat_name("bob");
	int			grade = 1;

	try
	{
		RobotomyRequestForm	Form("home");
		Bureaucrat				bureaucrat(bureaucrat_name, grade);
		std::cout << Form << bureaucrat;

		bureaucrat.signForm(Form);
		bureaucrat.executeForm(Form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}

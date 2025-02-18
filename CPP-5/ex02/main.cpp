/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:16:49 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/18 09:43:07 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::string	bureaucrat_name("bob");
	int			grade = 4;

	try
	{
		PresidentialPardonForm	Form("home");
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:16:49 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/19 09:34:32 by lchauvet         ###   ########.fr       */
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
		ShrubberyCreationForm	Shrubbery("home");
		PresidentialPardonForm	Presidential("home");
		RobotomyRequestForm		Robotomy("home");
		Bureaucrat				bureaucrat(bureaucrat_name, grade);

		std::cout << Shrubbery << bureaucrat;
		bureaucrat.signForm(Shrubbery);
		bureaucrat.executeForm(Shrubbery);

		std::cout << '\n' << Presidential << bureaucrat;
		bureaucrat.signForm(Presidential);
		bureaucrat.executeForm(Presidential);

		std::cout << '\n' << Robotomy << bureaucrat;
		bureaucrat.signForm(Robotomy);
		bureaucrat.executeForm(Robotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}

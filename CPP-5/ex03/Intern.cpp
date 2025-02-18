/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:36:04 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/18 14:31:36 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern&) {}

Intern&	Intern::operator=(const Intern& copy)
{
	(void)copy;
	return (*this);
}

static AForm*	do_ShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm*	do_RobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm*	do_PresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	AForm*	new_form;

	AForm*	(*do_array[3])(std::string) =
	{
		&do_ShrubberyCreationForm,
		&do_RobotomyRequestForm,
		&do_PresidentialPardonForm
	};

	std::string	Form_name[3] = 
	{
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};

	try
	{
		for (short i = 0; i < 3; i++)
		{
			if (name == Form_name[i])
			{
				new_form = do_array[i](target);
				std::cout << "Intern creates " << Form_name[i] << '\n';
				return (new_form);
			}
		}
		std::cout << "the given Form do not exist";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Intern creates fail to create " << name << ":" << '\n'
		<<  e.what() << '\n';
	}
	return (NULL);

}

Intern::~Intern(void) {}
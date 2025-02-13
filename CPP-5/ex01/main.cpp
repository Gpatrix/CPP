/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:16:49 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/13 17:10:41 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	std::string	form_name("A42");
	int			min_grade = 50;

	std::string	bureaucrat_name("bob");
	int			grade = 40;

	try
	{
		Form		form(form_name, min_grade, min_grade);
		Bureaucrat	bureaucrat(bureaucrat_name, grade);

		std::cout << form << bureaucrat;

		bureaucrat.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:46:01 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/17 13:45:43 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("ShrubberyForm", 72, 45), target("nowhere")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("ShrubberyForm", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
	: AForm(copy.getName(), copy.getminSignGrade(), copy.getminExecGrade())
{}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	(void)copy;
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getminExecGrade())
		throw ExecTooLowException();
	if (this->getis_signed() == false)
		throw AFormNotSignedException(this->getName());

	
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}
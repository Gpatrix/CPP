/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:46:01 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/17 13:45:43 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("PresidentialPardonForm", 25, 5), target("nowhere")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardonForm", 25, 5), target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
	: AForm(copy.getName(), copy.getminSignGrade(), copy.getminExecGrade())
{}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	(void)copy;
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getminExecGrade())
		throw GradeTooLowException();
	if (this->getis_signed() == false)
		throw AFormNotSignedException(this->getName());

	std::cout << bureaucrat.getName() << " has been pardoned by Zaphod Beeblebrox\n";
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}
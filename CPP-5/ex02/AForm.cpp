/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:50:54 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/13 16:54:02 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): minSignGrade(1), minExecGrade(1), is_signed(false) {}

AForm::AForm(
	std::string cpy_name,
	int cpy_minSignGrade,
	int cpy_minExecGrade
):
	name(cpy_name),
	minSignGrade(cpy_minSignGrade),
	minExecGrade(cpy_minExecGrade),
	is_signed(false)
{
	if (minExecGrade < 1 || minExecGrade < 1)
		throw AForm::GradeTooHighException();
	if (minExecGrade > 150 || minExecGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(
	const AForm& cpy_form
):
	name(cpy_form.getName()),
	minSignGrade(cpy_form.getminSignGrade()),
	minExecGrade(cpy_form.getminExecGrade())
{
	this->operator=(cpy_form);
}

AForm&	AForm::operator=(const AForm& cpy_Form)
{
	if (this == &cpy_Form)
		return (*this);
	
	this->is_signed = cpy_Form.getis_signed();
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const AForm& Aform)
{
	stream << Aform.getName() << ", AForm"
	<< "\n\tmin sign grade : " << Aform.getminSignGrade()
	<< "\n\tmin Exec grade : " << Aform.getminExecGrade()
	<< "\n\tis_signed      : " << Aform.getis_signed() << '\n';
	return (stream);
}

void	AForm::beSigned(Bureaucrat& Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->minSignGrade)
		throw AForm::GradeTooLowException();

	this->is_signed = true;
}

std::string	AForm::getName(void) const
{
	return (this->name);
}

int	AForm::getminSignGrade(void) const
{

	return (this->minSignGrade);
}

int	AForm::getminExecGrade(void) const
{
	return (this->minExecGrade);
}

int	AForm::getis_signed(void) const
{
	return (this->is_signed);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char*	AForm::ExecTooLowException::what() const throw()
{
	return ("Exec grade too low");
}

AForm::AFormNotSignedException::AFormNotSignedException(const std::string message) 
: _message(message) {}

const char*	AForm::AFormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

AForm::AFormNotSignedException::~AFormNotSignedException(void) throw()
{}


AForm::~AForm(void) {}

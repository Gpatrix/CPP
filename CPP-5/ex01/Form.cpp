/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:50:54 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/13 16:54:02 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): minSignGrade(1), minExecGrade(1), is_signed(false) {}

Form::Form(
	std::string& cpy_name,
	int& cpy_minSignGrade,
	int& cpy_minExecGrade
):
	name(cpy_name),
	minSignGrade(cpy_minSignGrade),
	minExecGrade(cpy_minExecGrade),
	is_signed(false)
{
	if (minExecGrade <= 1 || minExecGrade <= 1)
		throw Form::GradeTooHighException();
	if (minExecGrade >= 150 || minExecGrade >= 150)
		throw Form::GradeTooLowException();
}

Form::Form(
	const Form& cpy_form
):
	name(cpy_form.getName()),
	minSignGrade(cpy_form.getminSignGrade()),
	minExecGrade(cpy_form.getminExecGrade())
{
	this->operator=(cpy_form);
}

Form&	Form::operator=(const Form& cpy_Form)
{
	if (this == &cpy_Form)
		return (*this);
	
	this->is_signed = cpy_Form.getis_signed();
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const Form& form)
{
	stream << form.getName() << ", Form"
	<< "\n\tmin sign sign : " << form.getminSignGrade()
	<< "\n\tmin sign grade: " << form.getminSignGrade()
	<< "\n\tis_signed     : " << form.getis_signed() << '\n';
	return (stream);
}

void	Form::beSigned(Bureaucrat& Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->minSignGrade)
		throw Form::GradeTooLowException();

	this->is_signed = true;
}

std::string	Form::getName(void) const
{
	return (this->name);
}

int	Form::getminSignGrade(void) const
{

	return (this->minSignGrade);
}

int	Form::getminExecGrade(void) const
{
	return (this->minExecGrade);
}

int	Form::getis_signed(void) const
{
	return (this->is_signed);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

Form::~Form(void) {}

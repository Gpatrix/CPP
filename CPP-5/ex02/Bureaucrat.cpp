/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:10:59 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/17 10:45:19 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): name("anonymous"), grade(150) {}

Bureaucrat::Bureaucrat(std::string& new_name, int& new_grade):  name(new_name)
{
	if (new_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (new_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	
	this->grade = new_grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat): name(bureaucrat.getName())
{
	this->operator=(bureaucrat);
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	if (this == &bureaucrat)
		return (*this);

	this->grade = bureaucrat.getGrade();
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
	<< '\n';
	return (stream);
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn’t sign " << form.getName()
		<< " because " << e.what() << '\n';
	}
	
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->grade <= 1)
		throw (Bureaucrat::GradeTooHighException());

	this->grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->grade >= 150)
		throw (Bureaucrat::GradeTooLowException());

	this->grade++;
}

std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

Bureaucrat::~Bureaucrat(void) {}
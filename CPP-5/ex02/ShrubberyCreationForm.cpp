/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:46:01 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/19 09:12:39 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("ShrubberyCreationForm", 1, 1), target("nowhere")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
	: AForm(copy.getName(), copy.getminSignGrade(), copy.getminExecGrade())
{}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	(void)copy;
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getminExecGrade())
		throw GradeTooLowException();
	if (this->getis_signed() == false)
		throw AFormNotSignedException(this->getName());

	std::ofstream OutFile;

	OutFile.open((this->target + "_shrubbery").c_str(), std::ofstream::trunc | std::ifstream::out);

	if (!OutFile.is_open())
		throw CreateFileException(target);
	
	OutFile << ASCII_TREE;
	OutFile.close();
}

ShrubberyCreationForm::CreateFileException::CreateFileException(const std::string message) 
: _message(message) {}


const char*	ShrubberyCreationForm::CreateFileException::what() const throw()
{
	this->_message = "failed to create/open " + this->_message + "_shrubbery";
	return (this->_message.c_str());
}

ShrubberyCreationForm::CreateFileException::~CreateFileException(void) throw()
{}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}
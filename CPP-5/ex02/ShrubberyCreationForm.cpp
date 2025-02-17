/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:46:01 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/17 09:50:29 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
	target("nowhere"), AForm("ShrubberyCreationForm", 1, 1)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	target(target), AForm("ShrubberyCreationForm", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
	: AForm(copy.getName(), copy.getminSignGrade(), copy.getminExecGrade())
{}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() < this->getminExecGrade())
		throw ExecTooLowException();

	std::ofstream OutFile;

	OutFile.open(this->target + "_shrubbery", std::ofstream::trunc | std::ifstream::out);

	if (!OutFile.is_open())
		throw CreateFileException(target);
	
	OutFile << ASCII_TREE;
	OutFile.close();
}

ShrubberyCreationForm::CreateFileException::CreateFileException(const std::string target) 
: _target(target) {}

const char*	ShrubberyCreationForm::CreateFileException::what() const throw()
{
	return (("failed to create/open " + this->_target + "_shrubbery").c_str());
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}
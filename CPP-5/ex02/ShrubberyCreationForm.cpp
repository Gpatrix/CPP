/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:46:01 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/17 10:44:20 by lchauvet         ###   ########.fr       */
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

void	ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() < this->getminExecGrade())
		throw ExecTooLowException();

	std::ofstream OutFile;

	OutFile.open((this->target + "_shrubbery").c_str(), std::ofstream::trunc | std::ifstream::out);

	if (!OutFile.is_open())
		throw CreateFileException(target);
	
	OutFile << ASCII_TREE;
	OutFile.close();
}

ShrubberyCreationForm::CreateFileException::CreateFileException(const std::string target) 
: _target(target) {}

const char*	ShrubberyCreationForm::CreateFileException::what() const throw()
{
	this->_target = "failed to create/open " + this->_target + "_shrubbery";
	return (this->_target.c_str());
}

ShrubberyCreationForm::CreateFileException::~CreateFileException(void) throw()
{}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}
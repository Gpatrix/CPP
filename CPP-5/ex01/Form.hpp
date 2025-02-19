/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:53:50 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/19 08:55:33 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const int			minSignGrade;
		const int			minExecGrade;
		bool				is_signed;

	public:
		Form(void);
		Form(std::string, int, int);
		Form(const Form&);

		Form&	operator=(const Form&);


		void	beSigned(Bureaucrat&);

		std::string	getName(void) const;
		int			getminSignGrade(void) const;
		int			getminExecGrade(void) const;
		int			getis_signed(void) const;

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		~Form(void);
};

std::ostream&	operator<<(std::ostream& stream, const Form&);
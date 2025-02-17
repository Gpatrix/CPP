/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:53:50 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/14 13:09:55 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		const int			minSignGrade;
		const int			minExecGrade;
		bool				is_signed;

	public:
		AForm(void);
		AForm(std::string, int, int);
		AForm(const AForm&);

		AForm&	operator=(const AForm&);

		void					beSigned(Bureaucrat&);
		virtual void			execute(const Bureaucrat&) const = 0;

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

		class ExecTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		~AForm(void);
};

std::ostream&	operator<<(std::ostream& stream, const AForm&);
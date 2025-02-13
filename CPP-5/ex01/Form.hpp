/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:53:50 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/13 13:29:16 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name;
		const int			minSignGrade;
		const int			minExecGrade;
		bool				is_signed;

	public:
		Form(void);
		Form(std::string&, int&, int&);
		Form(const Form&);

		Form&	operator=(const Form&);

		friend std::ostream&	operator<<(std::ostream& stream, const Form&);

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:10:40 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/12 12:36:02 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat(std::string new_name, int& new_grade);

		std::string	getName(void) const;
		int			getGrade(void) const;
	
		friend std::ostream&	operator<<(std::ostream& flux, const Bureaucrat&);

		~Bureaucrat(void);
};
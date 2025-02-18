/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:39:06 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/18 09:27:34 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		const std::string target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm&);

		PresidentialPardonForm&	operator=(const PresidentialPardonForm&);

		void	execute(const Bureaucrat&) const;

		~PresidentialPardonForm(void);
};

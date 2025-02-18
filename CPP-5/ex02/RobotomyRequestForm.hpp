/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
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

class RobotomyRequestForm: public AForm
{
	private:
		const std::string target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm&);

		RobotomyRequestForm&	operator=(const RobotomyRequestForm&);

		void	execute(const Bureaucrat&) const;

		~RobotomyRequestForm(void);
};

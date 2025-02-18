/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:16:49 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/18 14:30:53 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"

int main(void)
{
	{
		Intern	someRandomIntern;
		AForm*	new_from;

		new_from = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
		if (!new_from)
			return (1);
		delete new_from;
	}
	return (0);
}

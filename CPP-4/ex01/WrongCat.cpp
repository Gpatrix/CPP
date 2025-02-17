/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:37:03 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/17 16:22:32 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat constructor\n";
	this->type = "Cat";
}

WrongCat::WrongCat(const WrongCat& copy)
{
	std::cout << "WrongCat copy constructor\n";
	if (this != &copy)
		this->operator=(copy);
}

WrongCat&	WrongCat::operator=(const WrongCat& assign)
{
	if (this != &assign)
	{
		this->type = assign.type;
	}
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "MIAOUUUUUUUUUUUUUUUUUUUUU" << '\n';
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructeur\n";
}

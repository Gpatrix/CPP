/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:37:03 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/30 10:09:11 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "Cat";
}

WrongCat::WrongCat(const WrongCat& copy)
{
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
	std::cout << "miaou" << '\n';
}

WrongCat::~WrongCat() {}

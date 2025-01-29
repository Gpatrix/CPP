/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:37:03 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/29 17:55:11 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	brains = new Brain();
}

Cat::Cat(const Cat& copy)
{
	if (this != &copy)
	{
		this->operator=(copy);
		brains = new Brain(*copy.brains);
	}
}

Cat&	Cat::operator=(const Cat& assign)
{
	if (this == &assign)
	{
		this->type = assign.type;
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "miaou" << '\n';
}

Cat::~Cat()
{
	delete brains;
}

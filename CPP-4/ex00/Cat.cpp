/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:37:03 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/17 15:36:32 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat constructor\n";
	this->type = "Cat";
}

Cat::Cat(const Cat& copy)
{
	std::cout << "Cat copy constructor\n";
	if (this != &copy)
		this->operator=(copy);
}

Cat&	Cat::operator=(const Cat& assign)
{
	if (this != &assign)
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
	std::cout << "Cat destructor\n";
}

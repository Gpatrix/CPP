/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:37:03 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/29 17:55:28 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	brains = new Brain();
}

Dog::Dog(const Dog& copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
		brains = new Brain(*copy.brains);
	}
}

Dog&	Dog::operator=(const Dog& assign)
{
	if (this == &assign)
	{
		this->type = assign.type;
		brains = assign.brains;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "wouf" << '\n';
}

Dog::~Dog()
{
	delete brains;
}

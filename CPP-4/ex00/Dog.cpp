/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:37:03 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/30 10:09:04 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
}

Dog::Dog(const Dog& copy)
{
	if (this != &copy)
		this->operator=(copy);
}

Dog&	Dog::operator=(const Dog& assign)
{
	if (this != &assign)
	{
		this->type = assign.type;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "wouf" << '\n';
}

Dog::~Dog() {}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:37:03 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/17 15:36:45 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog constructor\n";
	this->type = "Dog";
}

Dog::Dog(const Dog& copy)
{
	std::cout << "Dog copy constructor\n";
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
	std::cout << "Dog destructor\n";
	std::cout << "wouf" << '\n';
}

Dog::~Dog() {}

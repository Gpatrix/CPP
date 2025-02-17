/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:15:46 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/17 15:36:06 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal constructor\n";
	this->type = "Unknow";
}

Animal::Animal(const Animal& copy)
{
	std::cout << "Animal copy constructor\n";
	if (this != &copy)
		this->operator=(copy);
}

Animal&	Animal::operator=(const Animal& assign)
{
	if (this != &assign)
	{
		this->type = assign.type;
	}
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void Animal::makeSound(void) const
{
	std::cout << "[Unknown Animal] zzzz..." << '\n';
}

Animal::~Animal()
{
	std::cout << "Animal destructor\n";
}

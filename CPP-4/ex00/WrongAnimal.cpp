/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:15:46 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/17 15:37:14 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal constructor\n";
	this->type = "Unknow";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout << "WrongAnimal copy constructor\n";
	if (this != &copy)
		this->operator=(copy);
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& assign)
{
	if (this != &assign)
	{
		this->type = assign.type;
	}
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "[Unknown WrongAnimal] hhhhh..." << '\n';
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor\n";
}

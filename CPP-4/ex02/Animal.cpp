/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:15:46 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/30 11:41:06 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	this->type = "Unknow";
}

Animal::Animal(std::string type)
{
	this->type = type;
}

Animal::Animal(const Animal& copy)
{
	if (this != &copy)
		this->type = copy.type;
}

Animal&	Animal::operator=(const Animal& assign)
{

	if (this != &assign)
		this->type = assign.type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

Animal::~Animal()
{
	std::cout << "Animal destructor\n";
}

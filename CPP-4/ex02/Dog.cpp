/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:37:03 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/30 11:00:34 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	brain = new Brain();
}

Dog::Dog(const Dog& copy): Animal("Dog")
{
	brain = new Brain(*copy.brain);
}

Dog&	Dog::operator=(const Dog& assign)
{
	if (this != &assign)
	{
		this->type = assign.type;
		delete brain;
		brain = new Brain(*assign.brain);
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "wouf" << '\n';
}

Dog::~Dog()
{
	std::cout << "Dog destructor\n";
	delete brain;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:37:03 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/30 11:01:00 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
	brain = new Brain();
}

Cat::Cat(const Cat& copy): Animal("Cat")
{
	brain = new Brain(*copy.brain);
}

Cat&	Cat::operator=(const Cat& assign)
{
	if (this != &assign)
	{
		this->type = assign.type;
		delete brain;
		brain = new Brain(*assign.brain);
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
	delete brain;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:03:45 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/17 16:32:16 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain(void)
{
	std::cout << "Brain default constructor\n";
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Brain copy constructor\n";
	if (this != &copy)
		this->operator=(copy);
}

Brain&	Brain::operator=(const Brain& assign)
{
	if (this != &assign)
	{
		for (short index = 0; index < 100; index++)
			this->ideas[index] = assign.ideas[index];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor\n";
}

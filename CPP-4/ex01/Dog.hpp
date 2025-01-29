/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:34:59 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/29 16:07:19 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{

private:
	Brain*	brains;

public:
	Dog(void);
	Dog(const Dog&);

	Dog&	operator=(const Dog&);

	void makeSound(void) const;

	~Dog(void);
};

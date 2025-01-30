/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:10:35 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/30 10:57:02 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(std::string type);
	Animal(const Animal&);

	Animal&	operator=(const Animal&);

	std::string	getType(void) const;

	virtual void makeSound(void) const;

	virtual ~Animal(void);
};

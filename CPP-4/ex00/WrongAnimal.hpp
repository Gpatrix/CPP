/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:10:35 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/30 09:38:47 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal&);

	WrongAnimal&	operator=(const WrongAnimal&);

	std::string	getType(void) const;

	void makeSound(void) const;

	virtual ~WrongAnimal(void);
};

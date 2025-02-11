/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:50:50 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/11 16:00:04 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}

void	HumanB::attack(void)
{
	if (_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << '\n';
	else
		std::cout << this->_name << " attacks with his bare hands" << '\n';
}

void	HumanB::setWeapon(Weapon& new_weapon)
{
	this->_weapon = &new_weapon;
}

HumanB::~HumanB() {}

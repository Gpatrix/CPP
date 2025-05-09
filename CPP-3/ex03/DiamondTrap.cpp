/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:53:45 by lchauvet          #+#    #+#             */
/*   Updated: 2025/05/09 17:24:21 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(void): FragTrap("Name not define"), ScavTrap("Name not define")
{
	FragTrap	frag;
	std::cout << "DiamondTrap Default constructor called\n";

	this->Name = "Name not define";
	this->HitPoint		= FragTrap::getHitPoint();
	this->EnergyPoint	= ScavTrap::getEnergyPoint();
	this->AttackDamage	= FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(std::string Name) : FragTrap(Name + "_clap_name"), ScavTrap(Name + "_clap_name")
{
	std::cout << "DiamondTrap Name constructor called\n";

	this->Name = Name;
	this->HitPoint		= FragTrap::getHitPoint();
	this->EnergyPoint	= ScavTrap::getEnergyPoint();
	this->AttackDamage	= FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
{
	if (this != &copy)
		this->operator=(copy);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My name: " << this->Name << '\n'
			  << "ClapTrap name: " <<  this->ClapTrap::Name << '\n';
}


DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& assign)
{
	if (this != &assign)
	{
		this->Name = assign.getName();
		this->ScavTrap::Name = assign.ScavTrap::getName();
		this->HitPoint = assign.getHitPoint();
		this->EnergyPoint = assign.getEnergyPoint();
		this->AttackDamage = assign.getAttackDamage();
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called for " << this->Name << '\n';
}
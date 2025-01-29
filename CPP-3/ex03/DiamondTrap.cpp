/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:53:45 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/29 13:21:20 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap Default constructor called\n";
	this->Name = "Name not define";
	this->ClapTrap::Name = this->Name + "_clap_name";
	this->HitPoint = this->FragTrap::HitPoint;
	this->EnergyPoint = this->ScavTrap::EnergyPoint;
	this->AttackDamage = this->FragTrap::AttackDamage;
}

DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name + "_clap_name")
{
	std::cout << "DiamondTrap Name constructor called\n";
	this->ClapTrap::Name = Name + "_clap_name";
	this->Name = Name;
	this->HitPoint = this->FragTrap::HitPoint;
	this->EnergyPoint = this->ScavTrap::EnergyPoint;
	this->AttackDamage = this->FragTrap::AttackDamage;
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
		this->Name = assign.Name;
		this->ScavTrap::Name = assign.ScavTrap::Name;
		this->HitPoint = assign.HitPoint;
		this->EnergyPoint = assign.EnergyPoint;
		this->AttackDamage = assign.AttackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called for " << this->Name << '\n';
}
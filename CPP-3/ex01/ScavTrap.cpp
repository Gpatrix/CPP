/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:19:33 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/17 09:06:33 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap("Name not define")
{
	std::cout << "ScrapTrap Default constructor called\n";
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
}

ScavTrap::ScavTrap(std::string Name): ClapTrap(Name)
{
	std::cout << "ScrapTrap Name constructor called\n";
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
	if (this != &copy)
		this->operator=(copy);
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& assign)
{
	if (this != &assign)
	{
		this->Name = assign.Name;
		this->HitPoint = assign.HitPoint;
		this->EnergyPoint = assign.EnergyPoint;
		this->AttackDamage = assign.AttackDamage;
	}
	return (*this);
}

void ScavTrap::guardGate(void)
{
	std::cout << this->Name <<" is now in Gate keeper mode.\n";
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->HitPoint <= 0)
	{
		std::cout << this->Name << " is dead he can't attack any more\n";
	}
	else if (this->EnergyPoint <= 0)
	{
		std::cout << this->Name <<
		 " don't have enough energy to attack and he very is sad\n";
	}
	else
	{
		this->EnergyPoint--;
		std::cout << this->Name << " attacks with extreme power " << target <<
			", causing " << this->AttackDamage << " points of damage!\n";
	}
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called for " << this->Name << '\n';
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:30:52 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/14 12:21:30 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap Default constructor called\n";
	this->Name = "Name not define";
	this->HitPoint = 10;
	this->EnergyPoint = 10;
	this->AttackDamage = 0;
}

ClapTrap::ClapTrap(std::string Name)
{
	std::cout << "ClapTrap Name constructor called\n";
	this->Name = Name;
	this->HitPoint = 10;
	this->EnergyPoint = 10;
	this->AttackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	if (this != &copy)
		this->operator=(copy);
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& assign)
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

void	ClapTrap::attack(const std::string& target)
{
	if (this->HitPoint <= 0)
		std::cout << this->Name << " is dead he can't attack\n";
	else if (this->EnergyPoint <= 0)
	{
		std::cout << this->Name << " don't have enough energy to attack\n";
	}
	else
	{
		this->EnergyPoint--;
		std::cout << this->Name << " attacks " << target <<
			", causing " << this->AttackDamage << " points of damage!\n";
	}
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoint <= 0)
	{
		std::cout << this->Name << " is attacked even after being dead, shame\n";
	}
	else
	{
		this->HitPoint -= amount;
		if (this->HitPoint <= 0)
		{
			std::cout << this->Name << " as taken " << amount << " damage and died\n";
		}
		else
		{
			std::cout << this->Name << " as taken " << amount << " damage\n";
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->HitPoint <= 0)
		std::cout << this->Name << " is already dead he can't repair itself\n";
	else if (this->EnergyPoint <= 0)
		std::cout << this->Name << " don't have enough energy to repair\n";
	else
	{
		this->HitPoint += amount;
		this->EnergyPoint--;
		std::cout << this->Name << " as repair " << amount << " damage\n";
	}
}

std::string	ClapTrap::getName(void) const
{
	return (this->Name);
}

int			ClapTrap::getHitPoint(void) const
{
	return (this->HitPoint);
}

int			ClapTrap::getEnergyPoint(void) const
{
	return (this->EnergyPoint);
}

int		ClapTrap::getAttackDamage(void) const
{
	return (this->AttackDamage);
}

ClapTrap::~ClapTrap() 
{
	std::cout << "ClapTrap Destructor called for " << this->Name << '\n';
}
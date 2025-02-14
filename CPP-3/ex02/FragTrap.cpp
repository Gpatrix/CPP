/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:29:31 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/14 10:40:16 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap("Name not define")
{
	std::cout << "FragTrap Default constructor called\n";
	this->HitPoint = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
}

FragTrap::FragTrap(std::string Name): ClapTrap(Name)
{
	std::cout << "FragTrap Name constructor called\n";
	this->HitPoint = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy)
{
	if (this != &copy)
		this->operator=(copy);
}

FragTrap&	FragTrap::operator=(const FragTrap& assign)
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

void FragTrap::highFivesGuys(void)
{
	if (this->HitPoint <= 0)
		std::cout << this->Name << " is dead he can't high fives\n";
	else
		std::cout << this->Name <<" have made a high fives to himself.\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called for " << this->Name << '\n';
}
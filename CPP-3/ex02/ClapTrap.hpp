/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:21:45 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/29 12:42:11 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
protected:
	std::string	Name;
	int			HitPoint;
	int			EnergyPoint;
	int			AttackDamage;

public:
	ClapTrap(void);
	ClapTrap(std::string Name);
	ClapTrap(const ClapTrap&);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	int		getAttackDamage(void);

	ClapTrap&	operator=(const ClapTrap&);
	
	~ClapTrap();
};
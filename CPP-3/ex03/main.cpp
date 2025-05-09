/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:13:18 by lchauvet          #+#    #+#             */
/*   Updated: 2025/05/09 17:24:53 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	DiamondTrap	Baptiste("Baptiste");

	Baptiste.whoAmI();
	Baptiste.attack("Cap'n amoraru");
	std::cout << Baptiste.getAttackDamage() << "\n"
	<< Baptiste.getEnergyPoint() << "\n"
	<< Baptiste.getHitPoint() << "\n";

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:13:18 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/14 12:34:43 by lchauvet         ###   ########.fr       */
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
	DiamondTrap	Cap("Cap'n amoraru");

	Baptiste.whoAmI();
	Baptiste.attack("Cap'n amoraru");
	Cap.takeDamage(Baptiste.getAttackDamage());
	Cap.highFivesGuys();
	Cap.guardGate();

	return 0;
}

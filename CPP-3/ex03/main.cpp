/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:13:18 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/29 13:25:32 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	DiamondTrap	diamondtrap("bob");
	ScavTrap	scavtrap("Cap'n amoraru");
	ClapTrap	claptrap("Baptiste");
	FragTrap	fragtrap("Alex malefique");

	diamondtrap.whoAmI();
	diamondtrap.attack("Cap'n amoraru");
	scavtrap.takeDamage(diamondtrap.getAttackDamage());
	claptrap.attack("Baptiste");
	scavtrap.takeDamage(claptrap.getAttackDamage());
	scavtrap.beRepaired(18);
	scavtrap.guardGate();
	fragtrap.attack("Cap'n amoraru");
	scavtrap.takeDamage(fragtrap.getAttackDamage());

	return 0;
}

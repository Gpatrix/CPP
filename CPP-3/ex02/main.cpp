/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:13:18 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/14 10:43:02 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap scavtrap("Cap'n amoraru");
	ClapTrap claptrap("Baptiste");
	FragTrap fragtrap("Alex malefique");

	claptrap.attack("Cap'n amoraru");
	scavtrap.takeDamage(claptrap.getAttackDamage());
	scavtrap.beRepaired(18);
	scavtrap.guardGate();
	fragtrap.attack("Cap'n amoraru");
	scavtrap.takeDamage(fragtrap.getAttackDamage());
	fragtrap.attack("Cap'n amoraru");
	scavtrap.takeDamage(fragtrap.getAttackDamage());
	fragtrap.attack("Cap'n amoraru");
	scavtrap.takeDamage(fragtrap.getAttackDamage());
	fragtrap.attack("Cap'n amoraru");
	scavtrap.takeDamage(fragtrap.getAttackDamage());
	fragtrap.highFivesGuys();

	return 0;
}

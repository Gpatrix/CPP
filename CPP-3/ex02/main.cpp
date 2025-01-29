/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:13:18 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/29 12:43:21 by lchauvet         ###   ########.fr       */
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

	claptrap.attack("Baptiste");
	scavtrap.takeDamage(claptrap.getAttackDamage());
	scavtrap.beRepaired(18);
	scavtrap.guardGate();
	fragtrap.attack("Cap'n amoraru");
	scavtrap.takeDamage(fragtrap.getAttackDamage());

	return 0;
}

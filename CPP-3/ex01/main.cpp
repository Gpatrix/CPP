/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:13:18 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/29 12:23:14 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap scavtrap("Cap'n amoraru");
	ClapTrap claptrap("Baptiste");

	scavtrap.attack("Baptiste");
	claptrap.takeDamage(10);
	claptrap.attack("Cap'n amoraru");
	claptrap.beRepaired(0);
	scavtrap.guardGate();
	scavtrap.beRepaired(5);

	return 0;
}

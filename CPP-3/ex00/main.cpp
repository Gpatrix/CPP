/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:13:18 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/12 09:49:37 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap claptrap1("Cap'n amoraru");
	ClapTrap claptrap2("Baptiste");

	claptrap1.attack("Baptiste");
	claptrap2.takeDamage(0);
	claptrap2.beRepaired(5);
	claptrap2.beRepaired(5);
	claptrap2.beRepaired(5);
	claptrap2.beRepaired(5);
	claptrap2.beRepaired(5);
	claptrap2.beRepaired(5);
	claptrap2.beRepaired(5);
	claptrap2.beRepaired(5);
	claptrap2.beRepaired(5);
	claptrap2.beRepaired(5);
	claptrap2.beRepaired(5);

	return 0;
}

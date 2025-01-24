/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:18:01 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/24 10:54:43 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Zombie.hpp"

int main(void)
{
	Zombie*	zombie;
	int nb_of_zombie = 50000;

	zombie = zombieHorde(nb_of_zombie, "Cap'n amoraru");
	if (!zombie)
		return (EXIT_FAILURE);
	for (int i = 0; i < nb_of_zombie; i++)
	{
		zombie[i].announce();
	}
	
	delete [] zombie;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:18:01 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/23 17:30:04 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie*	zombie;

	randomChump(("Cap'n amoraru"));
	zombie = newZombie("Baptiste");
	zombie->announce();
	delete zombie;
	return (0);
}

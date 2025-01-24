/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:58:13 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/24 10:53:34 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	Zombie*	zombiehorde = new Zombie[N];
	if (!zombiehorde)
		return (NULL);
	for (int i = 0; i < N; i++)
		zombiehorde[i].set_name(name);
	return (zombiehorde);
}

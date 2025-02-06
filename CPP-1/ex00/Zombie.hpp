/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:54:13 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/06 13:37:43 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie(std::string name);
		~Zombie();
		
		void announce(void) const;
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:54:13 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/23 17:23:51 by lchauvet         ###   ########.fr       */
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
		
		void announce(void);
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

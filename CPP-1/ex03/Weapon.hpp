/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:35:29 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/11 16:01:35 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon();

		const std::string&	getType(void);
		void				setType(std::string new_type);
};

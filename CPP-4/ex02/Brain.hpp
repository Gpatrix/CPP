/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:02:47 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/30 10:03:51 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>


class Brain
{
public:
	std::string	ideas[100];

	Brain(void);
	Brain(const Brain&);

	Brain&	operator=(const Brain&);

	~Brain(void);
};

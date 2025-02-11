/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:11:09 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/11 16:41:14 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>
#include <iostream>

#define DEFAULT_MSG "[ Probably complaining about insignificant problems ]" 

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cout << DEFAULT_MSG;
		return (EXIT_SUCCESS);
	}

	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	
	int i = 0;
	while (i < 4 && levels[i] != argv[1])
		i++;
	
	switch (i)
	{
		case 0:
			std::cout << "[ " << levels[0] << " ]" << '\n';
			harl.complain(levels[0]);
			std::cout << '\n';
		case 1:
			std::cout << "[ " << levels[1] << " ]" << '\n';
			harl.complain(levels[1]);
			std::cout << '\n';
		case 2:
			std::cout << "[ " << levels[2] << " ]" << '\n';
			harl.complain(levels[2]);
			std::cout << '\n';
		case 3:
			std::cout << "[ " << levels[3] << " ]" << '\n';
			harl.complain(levels[3]);
			std::cout << '\n';
			break;
		default:
			std::cout << DEFAULT_MSG << '\n';
	}
	return (EXIT_SUCCESS);
}

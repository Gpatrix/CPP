/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:11:09 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/11 16:18:27 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
	Harl harl;

	harl.complain("DEBUG");
	std::cout << '\n';
	harl.complain("INFO");
	std::cout << '\n';
	harl.complain("WARNING");
	std::cout << '\n';
	harl.complain("ERROR");
	std::cout << '\n';
	harl.complain("HAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	return (EXIT_SUCCESS);
}

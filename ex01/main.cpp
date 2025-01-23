/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:27:42 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/23 12:54:15 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	my_PhoneBook;
	std::string	input;

	while (true)
	{
		input = "";
		std::cout << "Enter your command > ";
		getline(std::cin, input);
		if (std::cin.eof() || input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			my_PhoneBook.add();
		}
	}	
	return (EXIT_SUCCESS);
}

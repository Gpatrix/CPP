/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:20:52 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/23 13:06:57 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) 
{
	current_contact = 0;
}

bool valid_input(std::string input)
{
	for (std::string::iterator i = input.begin(); i < input.end(); i++)
	{
		if (*i != ' ' && *i != '\t')
			return (true);
	}
	return (false);
}

void	PhoneBook::add(void)
{
	std::string	input;
	std::string	question[5] = {"first name: ", "last name: ", "nickname: ",
						 "phone number: ", "darkest secret: "};
	std::string	answer[5];

	for (short i = 0; i < 5; i++)
	{
		while (1)
		{
			std::cout << question[i];
			getline(std::cin, input);
			if (std::cin.eof())
				return ;
			if (!valid_input(input))
			{
				std::cout << ERROR_EMPTY_STR << '\n';
				continue ;
			}
			break ;
		}
		answer[i] = input;
	}
	contact[current_contact].set_FirstName(answer[0]);
	contact[current_contact].set_LastName(answer[1]);
	contact[current_contact].set_Nickname(answer[2]);
	contact[current_contact].set_PhoneNumber(answer[3]);
	contact[current_contact].set_DarkestSecret(answer[4]);
	current_contact = (current_contact + 1) % 8;
}

PhoneBook::~PhoneBook() {}

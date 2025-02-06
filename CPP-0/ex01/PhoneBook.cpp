/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:20:52 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/06 13:22:22 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) 
{
	current_contact = 0;
}

static bool _valid_input(std::string input)
{
	for (std::string::iterator i = input.begin(); i < input.end(); i++)
	{
		if (*i != ' ' && *i != '\t')
			return (true);
	}
	return (false);
}

void	PhoneBook::ADD(void)
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
			if (!_valid_input(input))
			{
				std::cout << ERROR_EMPTY_STR << '\n';
				continue ;
			}
			break ;
		}
		answer[i] = input;
	}
	this->contact[current_contact].set_FirstName(answer[0]);
	this->contact[current_contact].set_LastName(answer[1]);
	this->contact[current_contact].set_Nickname(answer[2]);
	this->contact[current_contact].set_PhoneNumber(answer[3]);
	this->contact[current_contact].set_DarkestSecret(answer[4]);
	current_contact = (current_contact + 1) % 8;
}

static std::string _cut_str(std::string str)
{
	if (str.size() > 10)
		return (str.substr(0, 9) + ".");
	return (str);

}

void	PhoneBook::print_contact(void)
{
	std::cout << std::setfill ('x') << std::setw (46) << '\n' << std::setfill (' ');
	std::cout << '|' << std::setw (10) << "index";
	std::cout << '|' << std::setw (10) << "first name";
	std::cout << '|' << std::setw (10) << "last name";
	std::cout << '|' << std::setw (10) << "nickname" << "|\n";
	for (size_t i = 0; i < 8; i++)
	{
		if (this->contact[i].get_FirstName().empty())
			break ;
		std::cout << '|' << std::setfill ('x') << std::setw (45) << "|\n" << std::setfill (' ');
		std::cout << '|' << std::setw (10) << i + 1;
		std::cout << '|' << std::setw (10) << _cut_str(this->contact[i].get_FirstName());
		std::cout << '|' << std::setw (10) << _cut_str(this->contact[i].get_LastName());
		std::cout << '|' << std::setw (10) << _cut_str(this->contact[i].get_Nickname()) << "|\n";
	}
	std::cout << std::setfill ('x') << std::setw (46) << '\n' << std::setfill (' ');
	
}

void	PhoneBook::SEARCH(void)
{
	std::string	input;
	short		index;

	if (this->contact[0].get_FirstName().empty())
	{
		std::cout << ERROR_EMPTY_CONTACT << '\n';
		return ;
	}
	print_contact();
	std::cout << '\n' << "select a index: ";
	getline(std::cin, input);
	if (std::cin.eof())
		return ;
	if (input.find_first_of("12345678") == input.npos || input.size() != 1
		|| this->contact[atoi(input.c_str()) - 1].get_FirstName().empty())
	{
		std::cout << '\n' << ERROR_BAD_INDEX << '\n';
		return ;
	}
	index = atoi(input.c_str()) - 1;
	std::cout << "First name: " << this->contact[index].get_FirstName() << '\n';
	std::cout << "Last name: " << this->contact[index].get_LastName() << '\n';
	std::cout << "Nickname: " << this->contact[index].get_Nickname() << '\n';
	std::cout << "Phone Number: " << this->contact[index].get_PhoneNumber() << '\n';
	std::cout << "Darkest secret: " << this->contact[index].get_DarkestSecret() << '\n';
}


PhoneBook::~PhoneBook() {}

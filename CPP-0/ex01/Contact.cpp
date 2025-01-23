/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:24:57 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/23 12:33:18 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

std::string	Contact::get_FirstName(void) const
{
	return (this->_FirstName);
}

std::string	Contact::get_LastName(void) const
{
	return (this->_LastName);
}

std::string	Contact::get_Nickname(void) const
{
	return (this->_Nickname);
}

std::string	Contact::get_PhoneNumber(void) const
{
	return (this->_PhoneNumber);
}

std::string	Contact::get_DarkestSecret(void) const
{
	return (this->_DarkestSecret);
}

void	Contact::set_FirstName(std::string new_FirstName)
{
	this->_FirstName = new_FirstName;
}

void	Contact::set_LastName(std::string new_LastName)
{
	this->_LastName = new_LastName;
}

void	Contact::set_Nickname(std::string new_Nickname)
{
	this->_Nickname = new_Nickname;
}

void	Contact::set_PhoneNumber(std::string new_PhoneNumber)
{
	this->_PhoneNumber = new_PhoneNumber;
}

void	Contact::set_DarkestSecret(std::string new_DarkestSecret)
{
	this->_DarkestSecret = new_DarkestSecret;
}

Contact::~Contact() {}

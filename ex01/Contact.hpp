/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:24:28 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/23 12:33:10 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Contact
{
private:
	std::string	_FirstName;
	std::string	_LastName;
	std::string	_Nickname;
	std::string	_PhoneNumber;
	std::string	_DarkestSecret;
public:
	Contact(void);
	~Contact();
	std::string	get_FirstName(void) const;
	std::string	get_LastName(void) const;
	std::string	get_Nickname(void) const;
	std::string	get_PhoneNumber(void) const;
	std::string	get_DarkestSecret(void) const;

	void		set_FirstName(std::string new_FirstName);
	void		set_LastName(std::string new_LastName);
	void		set_Nickname(std::string new_Nickname);
	void		set_PhoneNumber(std::string new_PhoneNumber);
	void		set_DarkestSecret(std::string new_DarkestSecret);
};

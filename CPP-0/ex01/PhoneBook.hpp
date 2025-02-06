/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:17:52 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/06 12:57:21 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

#define ERROR_EMPTY_STR		"\033[1;31mYou can not have empty value.\033[0m"
#define ERROR_EMPTY_CONTACT	"\033[1;33mSorry, no contact has been established.\033[0m"
#define ERROR_BAD_INDEX		"\033[1;31mSorry, no match for this index.\033[0m"

class PhoneBook
{
private:
	Contact	contact[8];
	short	current_contact;
	void	print_contact(void);

public:
	PhoneBook(void);
	~PhoneBook();

	void	ADD(void);
	void	SEARCH(void);
};



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:17:52 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/23 13:02:11 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"

#define ERROR_EMPTY_STR "you can not have empty value"

class PhoneBook
{
private:
	Contact	contact[8];
	short	current_contact;
public:
	PhoneBook(void);
	~PhoneBook();

	void	add(void);
};



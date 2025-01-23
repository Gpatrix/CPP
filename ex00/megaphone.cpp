/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:47:44 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/23 10:09:33 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#define DEFAULT "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std::cout << DEFAULT << std::endl;
		return (EXIT_SUCCESS);
	}

	std::string str;
	for (short i = 1; i < argc; i++)
		str.append(argv[i]);
	for (std::string::iterator i = str.begin(); i != str.end(); i++)
		std::cout << (char)toupper(*i);

	std::cout << '\n';
	return (0);
}

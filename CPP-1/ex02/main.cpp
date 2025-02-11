/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:07:21 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/11 15:49:00 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int main(void)
{
	std::string		str("HI THIS IS BRAIN");
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "memory address of:" << '\n';
	std::cout << std::setw(15) << "str: "<< &str << '\n';
	std::cout << std::setw(15) << "stringPTR: "<< stringPTR << '\n';
	std::cout << std::setw(15) << "stringREF: "<< &stringREF << "\n\n";

	std::cout << "value of:" << '\n';
	std::cout << std::setw(15) << "str: "<< str << '\n';
	std::cout << std::setw(15) << "stringPTR: "<< *stringPTR << '\n';
	std::cout << std::setw(15) << "stringREF: "<< stringREF << '\n';
	return (0);
}

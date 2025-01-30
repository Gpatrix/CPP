/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:09:14 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/30 10:57:40 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	delete dog;
	delete cat;

	Animal* animals[100];

	for (short i = 0; i < 100; i += 2)
	{
		animals[i] = new Dog();
		animals[i + 1] = new Cat();
	}
	for (short i = 0; i < 100; i += 2)
	{
		delete animals[i];
		delete animals[i + 1];
	}

	return (0);
}
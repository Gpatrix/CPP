/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:09:14 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/29 16:39:54 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	const Animal*	meta = new Animal();
	const Animal*	dog  = new Dog();
	const Cat		cat;

	std::cout << meta->getType() << '\n';
	meta->makeSound();

	std::cout << dog->getType() << '\n';
	dog->makeSound();

	std::cout << cat.getType() << '\n';
	cat.makeSound();


	delete meta;
	delete dog;
	return 0;
}
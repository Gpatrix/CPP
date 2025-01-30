/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:09:14 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/30 09:44:46 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const WrongAnimal*	wrongcat = new WrongCat();
	const Animal*	meta = new Animal();
	const Animal*	dog  = new Dog();
	const Cat		cat;

	std::cout << wrongcat->getType() << '\n';
	wrongcat->makeSound();

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
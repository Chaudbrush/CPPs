/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:45:16 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/17 17:50:07 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "Type: " << j->getType() << ", sound: " << std::endl;
	j->makeSound(); //will output the dog sound!
	
	std::cout << "Type: " << i->getType() << ", sound: " << std::endl;
	i->makeSound(); //will output the cat sound!

	std::cout << "Type: " << meta->getType() << ", sound: " << std::endl;
	meta->makeSound(); //will output NO sound!

	std::cout << std::endl << "Wrong classes: " << "";

	const WrongAnimal *p = new WrongAnimal();
	const WrongAnimal *o = new WrongCat();

	std::cout << "Type: " << p->getType() << ", sound: " << std::endl;
	p->makeSound(); //will output the cat sound!

	std::cout << "Type: " << o->getType() << ", sound: " << std::endl;
	o->makeSound(); //will output NO sound!

	delete meta;
	delete i;
	delete j;
	delete p;
	delete o;

	std::cout << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
	}
	std::cout << std::endl;
}
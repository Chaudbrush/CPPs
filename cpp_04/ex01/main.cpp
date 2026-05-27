/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:45:16 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/18 16:18:00 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	Animal animal;

	const int		zoo_max = 10;
	Animal			*zoo[zoo_max];

	for (int i = 0; i < zoo_max; i++)
	{
		if (i % 2)
			zoo[i] = new Cat();
		else
			zoo[i] = new Dog();
	}

	std::cout << std::endl << std::endl;


	Cat *a = new Cat;
	std::cout << std::endl;
	Cat b(*a);
	std::cout << std::endl;
	Cat c;
	std::cout << std::endl;
	c = b;
	{
		std::cout << std::endl << "---Inside brackets---" << std::endl;
		Cat d = c;
	}
	std::cout << std::endl;
	delete a;
	
	std::cout << std::endl << std::endl;

	for (int i = 0; i < zoo_max; i++)
		delete zoo[i];		
}
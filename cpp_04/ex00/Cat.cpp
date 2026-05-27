/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:11:45 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/12 15:33:45 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void Cat::makeSound() const
{
	std::cout << "Meow...Meow!" << std::endl;
}

// Orthodox Canonical Form
Cat::Cat()
{
	std::cout << "Cat Default Constructor called." << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat Copy Constructor called." << std::endl;
	this->type = other.type;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat Asignment operator called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called." << std::endl;	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:12:54 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/12 15:34:28 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void Dog::makeSound() const
{
	std::cout << "Woof...Woof!" << std::endl;
}

// Orthodox Canonical Form
Dog::Dog()
{
	std::cout << "Dog Default Constructor called." << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog Copy Constructor called." << std::endl;
	this->type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog Asignment operator called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called." << std::endl;	
}
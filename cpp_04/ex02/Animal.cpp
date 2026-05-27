/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:57:33 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/12 16:09:54 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


const std::string Animal::getType(void) const
{
	return (type);
}

void Animal::makeSound(void) const
{
	std::cout << "Animal sound..." << std::endl;
}

// Orthodox Canonical Form
Animal::Animal()
{
	this->type = "Animal";
	std::cout << "Animal Default Constructor called." << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal Copy Constructor called." << std::endl;
	this->type = other.type;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal Asignment operator called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called." << std::endl;	
}


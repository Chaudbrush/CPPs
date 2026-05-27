/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:12:54 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/18 16:10:42 by vloureir         ###   ########.fr       */
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
	m_brain = new Brain;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog Copy Constructor called." << std::endl;
	this->type = other.type;
	
	// Dog using assignment operator
	this->m_brain = new Brain;
	*this->m_brain = *other.m_brain;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog Asignment operator called." << std::endl;
	if (this != &other)
	{
		delete m_brain;
		this->type = other.type;

		// Dog using assignment operator
		this->m_brain = new Brain;
		*this->m_brain = *other.m_brain;	
	}
	return (*this);
}

Dog::~Dog()
{
	delete m_brain;
	std::cout << "Dog Destructor called." << std::endl;	
}
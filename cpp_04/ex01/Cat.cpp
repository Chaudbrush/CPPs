/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:11:45 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/18 16:11:17 by vloureir         ###   ########.fr       */
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
	m_brain = new Brain;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat Copy Constructor called." << std::endl;
	this->type = other.type;

	// Cat using copy constructor
	this->m_brain = new Brain(*other.m_brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat Asignment operator called." << std::endl;
	if (this != &other)
	{
		delete m_brain;
		this->type = other.type;
		
		// Cat using copy constructor
		this->m_brain = new Brain(*other.m_brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete m_brain;
	std::cout << "Cat Destructor called." << std::endl;	
}

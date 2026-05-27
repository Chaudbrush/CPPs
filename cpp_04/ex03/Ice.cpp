/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:44:47 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/19 14:44:57 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

AMateria* Ice::clone(void) const
{
	AMateria *tmp = new Ice(*this);
	return (tmp);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::Ice() : AMateria()
{
	this->type = "ice";
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	this->type = other.type;
}

Ice::~Ice()
{
	
}

Ice &Ice::operator=(const Ice& other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}
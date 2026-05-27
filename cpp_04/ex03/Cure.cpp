/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:49:58 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/19 14:50:15 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

AMateria* Cure::clone(void) const
{
	Cure *tmp = new Cure(*this);
	return (tmp);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::Cure() : AMateria()
{
	this->type = "cure";
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	this->type = other.type;
}

Cure::~Cure()
{
	
}

Cure &Cure::operator=(const Cure& other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

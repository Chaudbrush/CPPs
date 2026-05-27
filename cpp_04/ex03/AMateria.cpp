/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 19:19:45 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/19 14:52:32 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

AMateria::AMateria() : type("")
{

}

AMateria::AMateria(std::string const & type) : type(type)
{

}

AMateria::~AMateria()
{

}

AMateria &AMateria::operator=(const AMateria& other)
{
	(void)other;
	return (*this);
}

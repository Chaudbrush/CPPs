/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 19:19:07 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/19 14:34:56 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : actual_idx(0)
{
	slots = new AMateria*[4];
	for (int i = 0; i < 4; i++)
	{
		slots[i] = NULL;
		index_ref[i] = -1;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	this->actual_idx = other.actual_idx;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (index_ref[i] == 1)
			delete slots[i];
	}
	delete[] slots;
}

MateriaSource &MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		this->actual_idx = other.actual_idx;
	}
	return (*this);
}


void MateriaSource::learnMateria(AMateria* materia)
{
	if (actual_idx > 3)
	{
		delete materia;
		return ;
	}
	slots[actual_idx] = materia;
	index_ref[actual_idx] = 1;
	actual_idx++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (slots[i]->getType() == type)
		{
			return (slots[i]->clone());
		}
	}
	return 0;
}
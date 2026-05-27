/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 19:17:55 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/19 14:31:40 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	int i = 0;
	if (!m)
		return ;
	for ( ; i < 4; i++)
	{
		if (index_ref[i] == -1)
		{
			index_ref[i] = 1;
			slots[i] = m;
			return ;
		}
	}
	add_to_list(&list, m);
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || index_ref[idx] == -1)
		return ;
	add_to_list(&list, slots[idx]);
	slots[idx] = NULL;
	index_ref[idx] = -1;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || index_ref[idx] == -1 || !slots[idx])
		return ;
	slots[idx]->use(target);
}

// Orthodox Canonical Form
Character::Character() : name("No one")
{
	slots = new AMateria*[4];
	for (int i = 0; i < 4; i++)
	{
		slots[i] = NULL;
		index_ref[i] = -1;
	}
	list = NULL;
}

Character::Character(std::string name) : name(name)
{
	slots = new AMateria*[4];
	for (int i = 0; i < 4; i++)
	{
		slots[i] = NULL;
		index_ref[i] = -1;
	}
	list = NULL;
}

Character::Character(const Character& other)
{
	this->name = other.name;
	slots = new AMateria*[4];
	list = NULL;
	for (int i = 0; i < 4; i++)
	{
		index_ref[i] = other.index_ref[i];
		if (index_ref[i] == 1)
			slots[i] = other.slots[i]->clone();
		else
			slots[i] = NULL;
	}
}

Character::~Character()
{
	clear_slots(this->slots);
	lst_clear(list);
}

Character &Character::operator=(const Character& other)
{
	if (this != &other)
	{
		clear_slots(this->slots);
		lst_clear(list);
		this->name = other.name;
		slots = new AMateria*[4];
		for (int i = 0; i < 4; i++)
		{
			index_ref[i] = other.index_ref[i];
			if (index_ref[i] == 1)
				slots[i] = other.slots[i]->clone();
			else
				slots[i] = NULL;
		}
		list = NULL;
	}
	return (*this);
}

// Utils
void	Character::add_to_list(t_materia **list, AMateria *materia)
{
	t_materia *ptr = *list;
	t_materia *node = new t_materia;
	
	while (ptr)
	{
		if (ptr->data == materia)
			return ;
		ptr = ptr->next;
	}
	node->data = materia;
	node->next = *list;
	*list = node;
}

void	Character::lst_clear(t_materia *list)
{
	t_materia *ptr = list;

	while (ptr)
	{
		ptr = ptr->next;
		delete list->data;
		delete list;
		list = ptr;
	}
}

void Character::clear_slots(AMateria **slots)
{
	for (int i = 0;i < 4; i++)
	{
		if (slots[i])
			delete slots[i];
	}
	delete[] slots;
}
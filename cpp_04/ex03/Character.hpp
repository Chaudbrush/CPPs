/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:30:29 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/19 14:32:23 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria;

typedef struct s_materia
{
	AMateria 			*data;
	struct s_materia	*next;
}	t_materia;

class Character : public ICharacter
{
public:
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	Character();
	Character(std::string name);
	Character(const Character& other);
	~Character();

	Character &operator=(const Character& other);

private:
	std::string name;
	AMateria 	**slots;
	int			index_ref[4];
	t_materia	*list;

	void clear_slots(AMateria **slots);
	void lst_clear(t_materia *list);
	void add_to_list(t_materia **list, AMateria *materia);
};

#endif
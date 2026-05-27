/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:20:02 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/19 14:34:28 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	void learnMateria(AMateria* materia);
	AMateria *createMateria(std::string const & type);

	MateriaSource();
	MateriaSource(const MateriaSource& other);
	~MateriaSource();

	MateriaSource &operator=(const MateriaSource& other);

private:
	int			actual_idx;
	int			index_ref[4];
	AMateria	**slots;
};

#endif
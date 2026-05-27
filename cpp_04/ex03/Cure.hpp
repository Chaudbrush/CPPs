/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:49:50 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/19 14:51:41 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
public:
	AMateria* clone() const;
	void use(ICharacter& target);

	Cure();
	Cure(const Cure& other);
	~Cure();

	Cure &operator=(const Cure& other);
};

#endif
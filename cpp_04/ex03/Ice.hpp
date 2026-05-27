/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:45:04 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/19 14:48:30 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
public:
	AMateria* clone() const;
	void use(ICharacter& target);

	Ice();
	Ice(const Ice& other);
	~Ice();

	Ice &operator=(const Ice& other);
};

#endif
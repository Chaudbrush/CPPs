/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:17:52 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/07 16:18:05 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const	std::string &Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(std::string value)
{
	type = value;
}

Weapon::Weapon(std::string weap)
{
	type = weap;
}

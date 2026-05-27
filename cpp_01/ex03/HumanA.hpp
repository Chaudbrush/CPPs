/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:15:19 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/13 11:07:46 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA
{
public:
	void	setWeapon(Weapon &new_weapon);
	void	attack(void);
	HumanA(std::string new_name, Weapon &new_weapon);

private:
	std::string	name;
	Weapon		*weapon;
};

#endif
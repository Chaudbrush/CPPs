/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:15:22 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/13 11:07:52 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Weapon.hpp"

class HumanB
{
public:
	void	setWeapon(Weapon &new_weapon);
	void	attack(void);
	HumanB(std::string new_name);
	
private:
	std::string	name;
	Weapon		*weapon;
};

#endif
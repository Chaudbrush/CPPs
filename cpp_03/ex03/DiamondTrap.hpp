/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:02:01 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/12 12:08:31 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DIAMONDTRAP_HPP__
# define __DIAMONDTRAP_HPP__

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap
{
public:
	void	whoAmI(void);
	void	attack(const string& target);

	DiamondTrap();
	DiamondTrap(string name);
	DiamondTrap(const DiamondTrap& other);
	~DiamondTrap();

	DiamondTrap &operator=(const DiamondTrap& other);
private:
	std::string name;
};

#endif
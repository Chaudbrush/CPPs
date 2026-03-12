/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:48:35 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/09 14:43:40 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

# include <iostream>
# include <string>

typedef std::string string;

class ClapTrap
{
public:
	void	attack(const string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	setName(string name);
	string	getName(void) const;
	void	setAttackDamage(int amount);
	int		getAttackDamage(void) const;
	void 	setHitPoints(int amount);
	int		getHitPoints(void) const;
	void 	setEnergyPoints(int amount);
	int		getEnergyPoints(void) const;

	ClapTrap();
	ClapTrap(string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();

protected:
	int	m_hitPoints;
	int	m_energyPoints;
	int	m_attackDamage;
	string name;
};

#endif
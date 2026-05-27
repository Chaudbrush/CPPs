/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:48:35 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/16 14:39:10 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
public:
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	setName(std::string name);
	std::string	getName(void) const;
	void	setAttackDamage(int amount);
	int		getAttackDamage(void) const;
	void 	setHitPoints(int amount);
	int		getHitPoints(void) const;
	void 	setEnergyPoints(int amount);
	int		getEnergyPoints(void) const;

	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();
	
	ClapTrap &operator=(const ClapTrap &other);
protected:
	std::string name;		
	int	m_hitPoints;
	int	m_energyPoints;
	int	m_attackDamage;
};

#endif
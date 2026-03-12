/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:02:33 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/12 12:03:16 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"






void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::getName() << std::endl;
}



void	DiamondTrap::attack(const string& target)
{
	ScavTrap::attack(target);
}





// Orthodox Cannonical Form
DiamondTrap::DiamondTrap() : ClapTrap()
{
	std::cout << "DiamondTrap constructor called.\n";
	this->name = "DiamondDefault";
	ClapTrap::setName(name + "_clap_name");
	this->m_hitPoints = FragTrap::m_hitPoints;
	this->m_energyPoints = ScavTrap::m_energyPoints;
	this->m_attackDamage = FragTrap::m_attackDamage;
}

DiamondTrap::DiamondTrap(string name) : ClapTrap(name + "clap_name")
{
	std::cout << "DiamondTrap " << name << " constructor called.\n";
	this->name = name;
	ClapTrap::setName(name + "_clap_name");
	this->m_hitPoints = FragTrap::m_hitPoints;
	std::cout << "SCAV: " << ScavTrap::name;
	this->m_energyPoints = ScavTrap::m_energyPoints;
	this->m_attackDamage = FragTrap::m_attackDamage;

	// NEED TO 
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other)
{
	this->name = other.name;
	this->ClapTrap::name = name + "_clap_name";
	this->m_hitPoints = other.m_hitPoints;
	this->m_energyPoints = other.m_energyPoints;
	this->m_attackDamage = other.m_attackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called.\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->m_hitPoints = other.m_hitPoints;
		this->m_energyPoints = other.m_energyPoints;
		this->m_attackDamage = other.m_attackDamage;
	}
	return (*this);
}
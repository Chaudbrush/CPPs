/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:02:33 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/12 21:42:30 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am a DiamondTrap named: " << this->name;
	std::cout << ", my maker name is: " << ClapTrap::getName() << "." << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
		std::cout << "DiamondTrap " << getName() << " takes " << amount << " points of damage!";
		setHitPoints(-amount);
		std::cout << " Staying with " <<  getHitPoints() << " hitPoints." << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (getHitPoints() <= 0)
		std::cout << "Not enough hitPoints to act." << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "Not enough energyPoints to act." << std::endl;
	else
	{
		std::cout << "DiamondTrap " << getName() << " repairs, gaining " << amount << " points of health!";
		setEnergyPoints(-1);
		setHitPoints(amount);
		std::cout << " Staying with " << getEnergyPoints() << " energyPoints and " << getHitPoints() << " hitPoints."  << std::endl; 
	}
}


// Orthodox Canonical Form
DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->name = "Diamond_Default";
	ClapTrap::setName(name + "_clap_name");
	this->m_hitPoints = 100;
	this->m_energyPoints = 50;
	this->m_attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
	this->name = name;
	this->ClapTrap::name = name + "_clap_name";
	this->m_hitPoints = 100;
	this->m_energyPoints = 50;
	this->m_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->name = other.name;
	this->m_hitPoints = other.m_hitPoints;
	this->m_energyPoints = other.m_energyPoints;
	this->m_attackDamage = other.m_attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->ClapTrap::name = name + "_clap_name";
		this->m_hitPoints = other.m_hitPoints;
		this->m_energyPoints = other.m_energyPoints;
		this->m_attackDamage = other.m_attackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

std::string DiamondTrap::getName(void) const
{
	return (name);
}
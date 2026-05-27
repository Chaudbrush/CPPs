/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 21:30:36 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/12 14:48:16 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	ScavTrap::attack(const std::string& target)
{
	if (getHitPoints() <= 0)
		std::cout << "Not enough hitPoints to act." << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "Not enough energyPoints to act." << std::endl;
	else
	{
		std::cout << "ScavTrap " << getName() << " attacks " << target << " causing " << getAttackDamage() << " points of damage!";
		setEnergyPoints(-1);
		std::cout << " Staying with " << getEnergyPoints() << " energyPoints."  << std::endl; 
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
		std::cout << "ScavTrap " << getName() << " takes " << amount << " points of damage!";
		setHitPoints(-amount);
		std::cout << " Staying with " <<  getHitPoints() << " hitPoints." << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (getHitPoints() <= 0)
		std::cout << "Not enough hitPoints to act." << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "Not enough energyPoints to act." << std::endl;
	else
	{
		std::cout << "ScavTrap " << getName() << " repairs, gaining " << amount << " points of health!";
		setEnergyPoints(-1);
		setHitPoints(amount);
		std::cout << " Staying with " << getEnergyPoints() << " energyPoints and " << getHitPoints() << " hitPoints."  << std::endl; 
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << getName() << " initiated Gate keeper mode." << std::endl;
}


// Orthodox Canonical Form
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->name  = "Scav_Default";
	this->m_hitPoints = 100;
	this->m_energyPoints = 50;
	this->m_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
	this->name = name;
	this->m_hitPoints = 100;
	this->m_energyPoints = 50;
	this->m_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->name = other.name;
	this->m_hitPoints = other.m_hitPoints;
	this->m_energyPoints = other.m_energyPoints;
	this->m_attackDamage = other.m_attackDamage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->m_hitPoints = other.m_hitPoints;
		this->m_energyPoints = other.m_energyPoints;
		this->m_attackDamage = other.m_attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

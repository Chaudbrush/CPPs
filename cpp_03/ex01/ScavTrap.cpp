/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 21:30:36 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/11 18:37:09 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	ScavTrap::attack(const string& target)
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
	std::cout << "ScavTrap " << getName() << " initiate Gate keeper mode." << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	setName("ScavDefault");
	std::cout << "ScavTrap constructor called" << std::endl;
	this->m_hitPoints = ClapTrap::m_hitPoints + 90;
	this->m_energyPoints = ClapTrap::m_energyPoints + 40;
	this->m_attackDamage = ClapTrap::m_attackDamage + 20;
	
	// setHitPoints(90);
	// setEnergyPoints(40);
	// setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	
	this->m_hitPoints = ClapTrap::m_hitPoints + 90;
	this->m_energyPoints = ClapTrap::m_energyPoints + 40;
	this->m_attackDamage = ClapTrap::m_attackDamage + 20;
	
	// setHitPoints(90);
	// setEnergyPoints(40);
	// setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{

	// setHitPoints(other.getHitPoints());
	// setEnergyPoints(other.getEnergyPoints());
	// setAttackDamage(other.getAttackDamage());
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->setHitPoints(other.getHitPoints());
		setEnergyPoints(other.getEnergyPoints());
		setAttackDamage(other.getAttackDamage());
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

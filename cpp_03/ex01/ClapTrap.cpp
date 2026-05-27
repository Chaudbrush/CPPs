/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:10:44 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/12 12:27:40 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// ClapTrap Actions
void	ClapTrap::attack(const std::string& target)
{
	if (getHitPoints() <= 0)
		std::cout << "Not enough hitPoints to act." << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "Not enough energyPoints to act." << std::endl;
	else
	{
		std::cout << "ClapTrap " << getName() << " attacks " << target << " causing " << getAttackDamage() << " points of damage!";
		setEnergyPoints(-1);
		std::cout << " Staying with " << getEnergyPoints() << " energyPoints."  << std::endl; 
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
		std::cout << "ClapTrap " << getName() << " takes " << amount << " points of damage!";
		setHitPoints(-amount);
		std::cout << " Staying with " <<  getHitPoints() << " hitPoints." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (getHitPoints() <= 0)
		std::cout << "Not enough hitPoints to act." << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "Not enough energyPoints to act." << std::endl;
	else
	{
		std::cout << "ClapTrap " << getName() << " repairs, gaining " << amount << " points of health!";
		setEnergyPoints(-1);
		setHitPoints(amount);
		std::cout << " Staying with " << getEnergyPoints() << " energyPoints and " << getHitPoints() << " hitPoints."  << std::endl; 
	}
}

// Setter and Getter
void	ClapTrap::setName(std::string name)
{
	this->name = name;
}

std::string ClapTrap::getName(void) const
{
	return (name);
}

void	ClapTrap::setAttackDamage(int amount)
{
	m_attackDamage += amount;
}

int	ClapTrap::getAttackDamage(void) const
{
	return (m_attackDamage);
}

void	ClapTrap::setHitPoints(int amount)
{
	m_hitPoints += amount;
	if (m_hitPoints < 0)
		m_hitPoints = 0;
}

int		ClapTrap::getHitPoints(void) const
{
	return (m_hitPoints);
}

void	ClapTrap::setEnergyPoints(int amount)
{
	m_energyPoints += amount;
	if (m_energyPoints < 0)
		m_energyPoints = 0;
}

int		ClapTrap::getEnergyPoints(void) const
{
	return (m_energyPoints);
}

// Orthodox Cannonical Form
ClapTrap::ClapTrap() : name("Clap_Default"), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->name = other.name;
	this->m_hitPoints = other.m_hitPoints;
	this->m_energyPoints = other.m_energyPoints;
	this->m_attackDamage = other.m_attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->m_hitPoints = other.m_hitPoints;
		this->m_energyPoints = other.m_energyPoints;
		this->m_attackDamage = other.m_attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}
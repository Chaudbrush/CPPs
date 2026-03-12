/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:39:43 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/09 15:59:16 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


void	FragTrap::attack(const string& target)
{
	if (getHitPoints() <= 0)
		std::cout << "Not enough hitPoints to act." << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "Not enough energyPoints to act." << std::endl;
	else
	{
		std::cout << "FragTrap " << getName() << " attacks " << target << " causing " << getAttackDamage() << " points of damage!";
		setEnergyPoints(-1);
		std::cout << " Staying with " << getEnergyPoints() << " energyPoints."  << std::endl; 
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
		std::cout << "FragTrap " << getName() << " takes " << amount << " points of damage!";
		setHitPoints(-amount);
		std::cout << " Staying with " <<  getHitPoints() << " hitPoints." << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (getHitPoints() <= 0)
		std::cout << "Not enough hitPoints to act." << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "Not enough energyPoints to act." << std::endl;
	else
	{
		std::cout << "FragTrap " << getName() << " repairs, gaining " << amount << " points of health!";
		setEnergyPoints(-1);
		setHitPoints(amount);
		std::cout << " Staying with " << getEnergyPoints() << " energyPoints and " << getHitPoints() << " hitPoints."  << std::endl; 
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " sends a High Five!" << std::endl;
}

FragTrap::FragTrap() : ClapTrap()
{
	setName("FragDefault");
	std::cout << "FragTrap constructor called" << std::endl;
	setHitPoints(90);
	setEnergyPoints(90);
	setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	setHitPoints(90);
	setEnergyPoints(90);
	setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	setHitPoints(other.getHitPoints());
	setEnergyPoints(other.getEnergyPoints());
	setAttackDamage(other.getAttackDamage());
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->setHitPoints(other.getHitPoints());
		setEnergyPoints(other.getEnergyPoints());
		setAttackDamage(other.getAttackDamage());
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

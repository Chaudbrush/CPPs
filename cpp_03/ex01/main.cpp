/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:51:28 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/11 18:31:52 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap c3po("C-3PO");

	c3po.attack("Darth Vader");
	c3po.takeDamage(5);
	c3po.beRepaired(4);
	c3po.guardGate();

	std::cout << std::endl << std::endl;
	std::cout << "Clap:" << std::endl;
	std::cout << "HP:" << c3po.ClapTrap::getHitPoints() << std::endl;
	std::cout << "Energy:" << c3po.ClapTrap::getEnergyPoints() << std::endl;
	std::cout << "Attack:" << c3po.ClapTrap::getAttackDamage() << std::endl;

	std::cout << std::endl << std::endl;
	std::cout << "Scav:" << std::endl;
	std::cout << "HP:" << c3po.getHitPoints() << std::endl;
	std::cout << "Energy:" << c3po.getEnergyPoints() << std::endl;
	std::cout << "Attack:" << c3po.getAttackDamage() << std::endl;
}
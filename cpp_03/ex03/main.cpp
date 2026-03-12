/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:51:28 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/12 12:04:46 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap prime("Optimus Prime");

	//DiamondTrap other(prime);

	std::cout << "Prime: " << std::endl << std::endl;
	prime.whoAmI();

	std::cout << "Other: " << std::endl << std::endl;
	//other.whoAmI();
	
	prime.attack("Darth Vader");
	// other.attack("oooo");
	// other.ClapTrap::attack("frf");
	// other.FragTrap::attack("frf");
	std::cout << std::endl;
	// prime.takeDamage(5);
	// prime.beRepaired(4);
	// prime.highFivesGuys();

	std::cout << std::endl << std::endl;
	std::cout << "DiamondClap:" << std::endl;
	std::cout << "HP:" << prime.getHitPoints() << std::endl;
	std::cout << "Energy:" << prime.getEnergyPoints() << std::endl;
	std::cout << "Attack:" << prime.getAttackDamage() << std::endl;

	std::cout << std::endl << std::endl;
	std::cout << "Diamond:" << std::endl;
	//std::cout << "HP:" << other.getHitPoints() << std::endl;
	//std::cout << "Energy:" << other.getEnergyPoints() << std::endl;
	//std::cout << "Attack:" << other.getAttackDamage() << std::endl;

	std::cout << std::endl << std::endl;
}

// int		main(void)
// {
// 	DiamondTrap a("Eileen");
// 	std::cout << "Character: " << a.getName() << "\nHit Points: " << a.getHitPoints()
// 	<< "\nEnergy Points: " << a.getEnergyPoints() << "\nDamage: " << a.getAttackDamage() << std::endl;
// 	ClapTrap b("Beros");
// 	std::cout << "Character: " << b.getName() << "\nHit Points: " << b.getHitPoints()
// 	<< "\nEnergy Points: " << b.getEnergyPoints() << "\nDamage: " << b.getAttackDamage() << std::endl;
// 	a.whoAmI();
// 	a.attack("Beros");
// 	b.takeDamage(30);
// 	std::cout << "Character: " << b.getName() << "\nHit Points: " << b.getHitPoints()
// 	<< "\nEnergy Points: " << b.getEnergyPoints() << "\nDamage: " << b.getAttackDamage() << std::endl;
// 	std::cout << "Character: " << a.getName() << "\nHit Points: " << a.getHitPoints()
// 	<< "\nEnergy Points: " << a.getEnergyPoints() << "\nDamage: " << a.getAttackDamage() << std::endl;
// }
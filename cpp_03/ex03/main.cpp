/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:51:28 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/16 16:44:12 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
/*							CLAPTRAP						*/
	std::cout << "--- ClapTrap Constructors:" << std::endl;
	
	ClapTrap *clap1 = new ClapTrap;
	ClapTrap *clap2 = new ClapTrap("Jace");
	ClapTrap *clap3 = new ClapTrap(*clap1);
	ClapTrap *clap4 = new ClapTrap;
	
	*clap4 = *clap2;

	std::cout << std::endl << "--- ClapTrap Functions:" << std::endl;

	clap1->attack("Dirty Robot");
	clap1->takeDamage(5);
	clap1->beRepaired(4);

	std::cout << std::endl;

	clap2->attack("Vraska");
	clap2->takeDamage(8);
	clap2->beRepaired(1);

	std::cout << std::endl;

	clap3->attack("Recycled Robot");
	clap3->takeDamage(3);
	clap3->beRepaired(7);

	std::cout << std::endl;

	clap4->attack("Nicol Bolas");
	clap4->takeDamage(30);
	clap4->beRepaired(10);

	std::cout << std::endl << "--- ClapTrap Destructors:" << std::endl;
	delete clap1;
	delete clap2;
	delete clap3;
	delete clap4;

	std::cout << std::endl;

/*							SCAVTRAP						*/
	
	std::cout << "--- ScavTrap Constructors:" << std::endl;
	
	ScavTrap *scav1 = new ScavTrap;
	ScavTrap *scav2 = new ScavTrap("Jace");
	ScavTrap *scav3 = new ScavTrap(*scav1);
	ScavTrap *scav4 = new ScavTrap;
	
	*scav4 = *scav2;

	std::cout << std::endl << "--- ScavTrap Functions:" << std::endl;

	scav1->attack("Dirty Robot");
	scav1->takeDamage(5);
	scav1->beRepaired(4);
	scav1->guardGate();

	std::cout << std::endl;

	scav2->attack("Vraska");
	scav2->takeDamage(8);
	scav2->beRepaired(1);
	scav2->guardGate();

	std::cout << std::endl;

	scav3->attack("Recycled Robot");
	scav3->takeDamage(3);
	scav3->beRepaired(7);
	scav3->guardGate();

	std::cout << std::endl;

	scav4->attack("Nicol Bolas");
	scav4->takeDamage(30);
	scav4->beRepaired(10);
	scav4->guardGate();

	std::cout << std::endl << "--- ScavTrap Destructors:" << std::endl;
	delete scav1;
	delete scav2;
	delete scav3;
	delete scav4;

	std::cout << std::endl;
	
/*							FRAGTRAP						*/
	std::cout << "--- FragTrap Constructors:" << std::endl;
	
	FragTrap *frag1 = new FragTrap;
	FragTrap *frag2 = new FragTrap("Jace");
	FragTrap *frag3 = new FragTrap(*frag1);
	FragTrap *frag4 = new FragTrap;
	
	*frag4 = *frag2;

	std::cout << std::endl << "--- FragTrap Functions:" << std::endl;

	frag1->attack("Dirty Robot");
	frag1->takeDamage(5);
	frag1->beRepaired(4);

	std::cout << std::endl;

	frag2->attack("Vraska");
	frag2->takeDamage(8);
	frag2->beRepaired(1);

	std::cout << std::endl;

	frag3->attack("Recycled Robot");
	frag3->takeDamage(3);
	frag3->beRepaired(7);

	std::cout << std::endl;

	frag4->attack("Nicol Bolas");
	frag4->takeDamage(30);
	frag4->beRepaired(10);

	std::cout << std::endl << "--- FragTrap Destructors:" << std::endl;
	delete frag1;
	delete frag2;
	delete frag3;
	delete frag4;

	std::cout << std::endl;

/*							DIAMONDTRAP						*/
	
	std::cout << "--- DiamondTrap Constructors:" << std::endl;
	
	DiamondTrap *diamond1 = new DiamondTrap;
	DiamondTrap *diamond2 = new DiamondTrap("Jace");
	DiamondTrap *diamond3 = new DiamondTrap(*diamond1);
	DiamondTrap *diamond4 = new DiamondTrap;
	
	*diamond4 = *diamond2;

	std::cout << std::endl << "--- DiamondTrap Functions:" << std::endl;

	diamond1->attack("Dirty Robot");
	diamond1->takeDamage(5);
	diamond1->beRepaired(4);
	diamond1->whoAmI();

	std::cout << std::endl;

	diamond2->attack("Vraska");
	diamond2->takeDamage(8);
	diamond2->beRepaired(1);
	diamond2->whoAmI();

	std::cout << std::endl;

	diamond3->attack("Recycled Robot");
	diamond3->takeDamage(3);
	diamond3->beRepaired(7);
	diamond3->whoAmI();

	std::cout << std::endl;

	diamond4->attack("Nicol Bolas");
	diamond4->takeDamage(30);
	diamond4->beRepaired(10);
	diamond4->whoAmI();

	std::cout << std::endl << "--- DiamondTrap Destructors:" << std::endl;
	delete diamond1;
	delete diamond2;
	delete diamond3;
	delete diamond4;
}
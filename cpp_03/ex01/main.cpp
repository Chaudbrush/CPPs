/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:51:28 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/12 14:55:20 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
}
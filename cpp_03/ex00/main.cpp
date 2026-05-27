/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:51:28 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/12 14:54:37 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
}
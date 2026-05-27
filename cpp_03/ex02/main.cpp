/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:51:28 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/12 14:56:06 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

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
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:51:28 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/12 11:41:35 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap robot1;
	ClapTrap robot2("Jace");
	ClapTrap robot3(robot1);
	ClapTrap robot4;

	robot4 = robot2;

	std::cout << std::endl << "ClapTrap tests:" << std::endl << std::endl;

	robot1.attack("Extra random Robot");
	robot1.takeDamage(5);
	robot1.beRepaired(4);

	std::cout << std::endl;

	robot2.attack("Vraska");
	robot2.takeDamage(8);
	robot2.beRepaired(1);

	std::cout << std::endl;

	robot3.attack("Recycled Robot");
	robot3.takeDamage(3);
	robot3.beRepaired(7);

	std::cout << std::endl;

	robot4.attack("Nicol Bolas");
	robot4.takeDamage(1);
	robot4.beRepaired(10);

	std::cout << std::endl;
}
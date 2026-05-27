/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:13:28 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/08 22:14:23 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	std::cout << "Human A: " << std::endl;
	{	
		Weapon club("simple club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("bloody spiked club");
		bob.attack();
	}
	std::cout << "Human B: " << std::endl;
	{
		Weapon	club = Weapon("crude spiked club");
		Weapon	bat = Weapon("baseball bat");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		jim.setWeapon(bat);
		jim.attack();
		bat.setType("bloody spiked baseball bat");
		jim.attack();
	}
}
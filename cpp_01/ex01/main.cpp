/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:42:29 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/13 11:21:18 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		n = 7;
	Zombie	*new_zombie = NULL;

	new_zombie = new_zombie->zombieHorde(n, "Hisoka");
	for (int i = 0; i < n; i++)
	{
		std::cout << "Index: " << i << " - address: " << &new_zombie[i] << std::endl;
		new_zombie[i].announce();
	}
	delete[] new_zombie;
}
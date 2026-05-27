/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 08:19:44 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/06 12:20:41 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string str)
{
	Zombie	*tmp;

	tmp = new Zombie;
	tmp->set_name(str);
	tmp->announce();
	return (tmp);
}
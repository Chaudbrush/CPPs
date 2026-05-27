/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 08:05:57 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/13 11:07:29 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		void announce(void);
		void set_name(std::string name);
		std::string get_name(void) const;
		~Zombie();
};
	
Zombie	*newZombie(std::string name);
void randomChump(std::string name);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:57:46 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/17 17:51:20 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
public:
	virtual void	makeSound() const;
	const std::string getType(void) const;

	Animal();
	Animal(const Animal& other);
	virtual ~Animal();

	Animal &operator=(const Animal& other);
protected:
	std::string type;
};

#endif
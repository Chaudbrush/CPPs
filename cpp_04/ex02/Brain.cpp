/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:16:41 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/18 16:12:16 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Orthodox Canonical Form
Brain::Brain()
{
	std::cout << "Brain Default Constructor called." << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain Copy Constructor called." << std::endl;
	std::copy(other.ideas, other.ideas + 100, this->ideas);
	// for (int i = 0; i < 100; i++)
	// {
	// 	this->ideas[i] = other.ideas[i];
	// }
}

Brain &Brain::operator=(const Brain& other)
{
	std::cout << "Brain Assignment Operator called." << std::endl;
	if (this != &other)
	{
		std::copy(other.ideas, other.ideas + 100, this->ideas);
		// for (int i = 0; i < 100; i++)
		// {
		// 	this->ideas[i] = other.ideas[i];
		// }
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called." << std::endl;	
}
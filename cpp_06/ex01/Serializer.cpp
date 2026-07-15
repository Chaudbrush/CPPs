/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:37:02 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/09 11:56:03 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t tmp = reinterpret_cast<uintptr_t>(ptr);
	return (tmp);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *tmp = reinterpret_cast<Data*>(raw);
	return (tmp);
}

// Useless Cannonical Form
Serializer::Serializer()
{
	
}
Serializer::Serializer(const Serializer& other)
{
	(void)other;	
}
Serializer::~Serializer()
{
	
}

Serializer &Serializer::operator=(const Serializer& other)
{
	(void)other;
	return (*this);
}
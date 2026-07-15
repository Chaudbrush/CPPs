/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:37:04 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/09 11:54:32 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stdint.h>
# include <iostream>
# include "Data.hpp"

class Serializer
{
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(const Serializer& other);
	~Serializer();

	Serializer &operator=(const Serializer& other);
};
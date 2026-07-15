/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 11:25:31 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/13 14:35:12 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cstdlib>
# include <cstring>
# include <iomanip>
# include <iostream>
# include <string>

template <typename T>
class Array
{
public:
	void print(void) {
		for (unsigned int i = 0; i < m_size; i++)
			std::cout << array[i] << " ";
		std::cout << std::endl; 
	}

	void setValue(T value, unsigned int index) {
		this->array[index] = value;
	}

	unsigned int size(void) const { return (m_size); } // CAN THIS BE HERE? CANT USE .CPP ???

	Array();
	Array(unsigned int n);
	Array(const Array& other);
	~Array();

	Array& operator=(const Array& other);
	T& operator[](unsigned int index);

private:
	T *array;
	unsigned int m_size;
};

#include "Array.tpp"
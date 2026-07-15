/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 11:30:46 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/13 14:41:04 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(new T[1]), m_size(1)
{
	std::memset(array, 0, sizeof(T));
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), m_size(n)
{
	std::memset(array, 0, sizeof(T) * n);
}

template <typename T>
Array<T>::Array(const Array& other) : array(new T[other.m_size]), m_size(other.m_size)
{
	for (unsigned int i = 0; i < m_size; i++)
		array[i] = other.array[i];
}

template <typename T>
Array<T>::~Array()
{
	if (array)
		delete[] array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		T *tmp;
	
		m_size = other.m_size;
		tmp = new T[m_size];
		for (unsigned int i = 0; i < m_size; i++)
			tmp[i] = other.array[i];
		if (array)	
			delete[] array;
		array = tmp;
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index > m_size - 1)
		throw(std::out_of_range("-error: out of range"));
	return (array[index]);
}
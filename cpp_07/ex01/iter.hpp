/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 09:42:39 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/04 18:28:53 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

template<typename T>
void iter(T *arr, const int length, void (*f)(T&))
{
	for (int i = 0; i < length; i++)
		f(arr[i]);
}
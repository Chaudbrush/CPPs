/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 08:24:54 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/12 15:45:48 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void swap(T &a, T &b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T min(const T& a, const T& b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename T>
T max(const T& a, const T& b)
{
	if (a > b)
		return (a);
	return (b);
}
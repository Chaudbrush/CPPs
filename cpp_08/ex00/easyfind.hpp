/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 16:26:44 by vloureir          #+#    #+#             */
/*   Updated: 2026/06/19 15:07:45 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <algorithm>

template <typename T>
int easyfind(T data, int target)
{
	typename T::iterator it;

	it = find(data.begin(), data.end(), target);
	if (it != data.end())
		return (0);
	return (-1);
}
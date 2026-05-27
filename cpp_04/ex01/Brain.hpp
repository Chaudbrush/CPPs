/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:16:38 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/18 16:08:42 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <cstring>
# include <iostream>
# include <string>

class Brain
{
public:
	Brain();
	Brain(const Brain& other);
	~Brain();

	Brain &operator=(const Brain& other);

private:
	std::string ideas[100];
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 21:52:42 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/09 11:54:44 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cmath>
# include <cstring>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <string>
# include <cerrno>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

class ScalarConverter
{
public:
	static void convert(std::string literal);

private:
	// Shouldnt be instantiable, why I need this?
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();

	ScalarConverter& operator=(const ScalarConverter& other);
};
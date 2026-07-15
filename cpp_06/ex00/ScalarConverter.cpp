/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 21:51:57 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/09 12:27:25 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string literal)
{
	unsigned char c = literal[0];
	char *end_int = NULL;
	char *end_double = NULL;
	long numInt = strtol(literal.c_str(), &end_int, 10);
	long double numDouble = strtod(literal.c_str(), &end_double);

	if (literal.empty() == true || (literal.length() > 1 && c == ' ')) { // INVALID
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;	
	}
	else if (literal.length() == 1 &&  !std::isdigit(c)) { // VALID CHAR
		if (c < 32 || c > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
	}
	else if (!end_int[0]) { // VALID INT
		if (numInt < 0 || numInt > 255)
			std::cout << "char: impossible" << std::endl;
		else if (numInt < 32 || numInt > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(numInt) << "\'" << std::endl;
		if (numInt > INT_MAX || numInt < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << numInt << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(numInt) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(numInt) << std::endl;		
	}
	else if (!end_double[0] || strcmp(end_double, "f") == 0) { // VALID FLOAT
		if (std::isinf(numDouble) == true || std::isnan(numDouble)|| numInt > INT_MAX || numInt < INT_MIN) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}
		else {
			if (numInt < 0 || numInt > 255)
				std::cout << "char: impossible" << std::endl;
			else if (numInt < 32 || numInt > 126)
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << static_cast<char>(numDouble) << "'" << std::endl;
			if (numInt > INT_MAX || numInt < INT_MIN)
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(numDouble) << std::endl;
		}
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(numDouble) << "f" << std::endl;
		std::cout << "double: " << numDouble << std::endl;
	}
	else { // INVALID
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;	
	}
}

// Useless Cannonical Form
ScalarConverter::ScalarConverter()
{
	
}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;	
}
ScalarConverter::~ScalarConverter()
{
	
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}
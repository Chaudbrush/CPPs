/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 10:14:26 by vloureir          #+#    #+#             */
/*   Updated: 2026/07/12 07:53:38 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av)
{
	RPN data;

	if (ac != 2)
	{
		std::cerr << "\e[38;5;160mError\e[0m: Missing arguments\n";
		return (1);
	}
	std::string check = data.evalLine(av[1]);
	if (check.compare("ok"))
	{
		std::cerr << "\e[38;5;160mError\e[0m: " << check << std::endl;
		return (1);
	}
	return (0);
}
